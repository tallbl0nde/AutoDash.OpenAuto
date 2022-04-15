#include <QGuiApplication>

#include "OpenAutoWorker.hpp"

OpenAutoWorker::OpenAutoWorker(const std::function<void(bool)> & connectedCallback, QWidget * videoFrame) :
    QObject(nullptr),
    configuration(std::make_shared<openauto::configuration::Configuration>()),
    ioService(),
    ioWork(this->ioService),
    TCPWrapper(),
    USBWrapper((libusb_init(&this->USBContext), this->USBContext)),
    queryFactory(this->USBWrapper, this->ioService),
    queryChainFactory(this->USBWrapper, this->ioService, this->queryFactory),
    serviceFactory(this->ioService, this->configuration, videoFrame, connectedCallback, true /* night mode */),
    entityFactory(this->ioService, this->configuration, this->serviceFactory),
    USBHub(std::make_shared<aasdk::usb::USBHub>(this->USBWrapper, this->ioService, this->queryChainFactory)),
    connectedAccessoriesEnumerator(std::make_shared<aasdk::usb::ConnectedAccessoriesEnumerator>(this->USBWrapper, this->ioService, this->queryChainFactory)),
    openAutoApp(std::make_shared<openauto::App>(this->ioService, this->USBWrapper, this->TCPWrapper, this->entityFactory, this->USBHub, this->connectedAccessoriesEnumerator))
    {

    // TODO: Add toggle for night mode

    this->createIOServiceWorkers();
    this->createUSBWorkers();

    this->openAutoApp->waitForDevice(true);
}

OpenAutoWorker::~OpenAutoWorker() {
    this->ioService.stop();

    for (std::thread & thread : this->threadPool) {
        thread.join();
    }

    libusb_exit(this->USBContext);
}

void OpenAutoWorker::createIOServiceWorkers() {
    // TODO: Update based on cores?
    int count = 4;

    for (int i = 0; i < count; i++) {
        this->threadPool.emplace_back([this]() {
            this->ioService.run();
        });
    }
}

void OpenAutoWorker::createUSBWorkers() {
    // TODO: Update based on cores?
    int count = 4;

    auto w = [this]() {
        timeval eventTimeout = {180, 0};
        while (!this->ioService.stopped()) {
            libusb_handle_events_timeout_completed(this->USBContext, &eventTimeout, nullptr);
        }
    };

    for (int i = 0; i < count; i++) {
        this->threadPool.emplace_back(w);
    }
}
