#include <QGridLayout>
#include <QLabel>

#include "OpenAutoFrame.hpp"
#include "widget/OpenAutoWidget.hpp"
#include "OpenAutoWorker.hpp"

OpenAutoFrame::OpenAutoFrame(QWidget * parent) : QWidget(parent) {
    // Create stacked widget to swap between connect message
    // and actual stream
    this->stack = new QStackedWidget();

    // Connect message
    QWidget * connectWidget = new QWidget();
    QLabel * label = new QLabel("Connect device to start Android Auto", connectWidget);
    label->setAlignment(Qt::AlignCenter);
    this->stack->addWidget(connectWidget);

    // Android auto frame
    Widget::OpenAutoWidget * androidAutoFrame = new Widget::OpenAutoWidget();
    this->stack->addWidget(androidAutoFrame);

    // Create OpenAutoWorker and link everything up
    this->worker = new OpenAutoWorker([this](bool connected) {
        this->showAndroidAuto(connected);
    }, androidAutoFrame);

    // Display child stacked widget
    QGridLayout * layout = new QGridLayout(this);
    layout->addWidget(this->stack);
}

void OpenAutoFrame::showAndroidAuto(const bool show) {
    this->stack->setCurrentIndex(show ? 1 : 0);
}
