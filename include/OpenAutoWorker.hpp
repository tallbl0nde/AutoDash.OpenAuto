#ifndef OPENAUTOWORKER_HPP
#define OPENAUTOWORKER_HPP

#include "aasdk/TCP/TCPWrapper.hpp"
#include "aasdk/USB/AccessoryModeQueryChain.hpp"
#include "aasdk/USB/AccessoryModeQueryChainFactory.hpp"
#include "aasdk/USB/AccessoryModeQueryFactory.hpp"
#include "aasdk/USB/ConnectedAccessoriesEnumerator.hpp"
#include "aasdk/USB/USBHub.hpp"
#include "openauto/App.hpp"
#include "openauto/Configuration/Configuration.hpp"
#include "openauto/Configuration/IConfiguration.hpp"
#include "openauto/Configuration/RecentAddressesList.hpp"
#include "openauto/Service/AndroidAutoEntityFactory.hpp"
#include "openauto/Service/ServiceFactory.hpp"

#include <QObject>
#include <thread>
#include <vector>

class OpenAutoWorker : public QObject {
    Q_OBJECT

    private:
        // OpenAuto configuration object.
        std::shared_ptr<openauto::configuration::Configuration> configuration;

        // IDK what half of this is.
        libusb_context * USBContext;
        boost::asio::io_service ioService;
        boost::asio::io_service::work ioWork;
        aasdk::tcp::TCPWrapper TCPWrapper;
        aasdk::usb::USBWrapper USBWrapper;
        aasdk::usb::AccessoryModeQueryFactory queryFactory;
        aasdk::usb::AccessoryModeQueryChainFactory queryChainFactory;
        openauto::service::ServiceFactory serviceFactory;
        openauto::service::AndroidAutoEntityFactory entityFactory;
        std::shared_ptr<aasdk::usb::USBHub> USBHub;
        std::shared_ptr<aasdk::usb::ConnectedAccessoriesEnumerator> connectedAccessoriesEnumerator;

        // OpenAuto application.
        std::shared_ptr<openauto::App> openAutoApp;

        // Thread pool for USB and IO workers.
        std::vector<std::thread> threadPool;

        // Creates thread workers for IO handling.
        void createIOServiceWorkers();

        // Creates thread workers for USB handling.
        void createUSBWorkers();

    public:
        // Constructs a new OpenAutoWorker.
        // Accepts: Method to invoke with flag indicating if an active connection is present.
        //          Pointer to frame object
        OpenAutoWorker(const std::function<void(bool)> &, QWidget *);

        // Destroys the object.
        ~OpenAutoWorker();
};

#endif
