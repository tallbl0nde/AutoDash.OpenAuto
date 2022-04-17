#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMovie>

#include "OpenAutoFrame.hpp"
#include "widget/OpenAutoWidget.hpp"
#include "OpenAutoWorker.hpp"

OpenAutoFrame::OpenAutoFrame(QWidget * parent) : QWidget(parent) {
    // Create stacked widget to swap between connect message
    // and actual stream
    this->stack = new QStackedWidget();

    // Connect message
    QWidget * connectWidget = new QWidget();
    QHBoxLayout * layout = new QHBoxLayout(connectWidget);

    QLabel * animationLabel = new QLabel(connectWidget);
    QMovie * animation = new QMovie(":/OpenAuto/animated/pulsing-circles.apng");        // TODO: Delete
    animationLabel->setMovie(animation);
    animation->start();
    layout->addWidget(animationLabel, 0, Qt::AlignVCenter);

    QLabel * label = new QLabel("Connect device to start Android Auto", connectWidget);
    layout->addWidget(label, 0, Qt::AlignVCenter);

    this->stack->addWidget(connectWidget);

    // Android auto frame
    Widget::OpenAutoWidget * androidAutoFrame = new Widget::OpenAutoWidget();
    this->stack->addWidget(androidAutoFrame);

    // Create OpenAutoWorker and link everything up
    this->worker = new OpenAutoWorker([this](bool connected) {
        this->showAndroidAuto(connected);
    }, androidAutoFrame);

    // Display child stacked widget
    QGridLayout * layout2 = new QGridLayout(this);
    layout2->addWidget(this->stack);
}

void OpenAutoFrame::showAndroidAuto(const bool show) {
    this->stack->setCurrentIndex(show ? 1 : 0);
}
