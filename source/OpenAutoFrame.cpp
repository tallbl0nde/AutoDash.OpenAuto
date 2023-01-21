#include <QGraphicsOpacityEffect>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMovie>

#include "OpenAutoFrame.hpp"
#include "OpenAutoWorker.hpp"
#include "widget/OpenAutoWidget.hpp"

OpenAutoFrame::OpenAutoFrame(QWidget * parent) : QStackedWidget(parent) {
    // Create stacked widget to swap between connect message
    // and actual stream
    this->setGeometry(parent->rect());
    QGridLayout * layout = new QGridLayout(this);
    layout->setMargin(0);

    // Connect frame
    this->addWidget(this->createConnectWidget(this));

    // Android auto frame
    QWidget * androidAutoWidget = this->createAndroidAutoWidget(this);
    this->addWidget(androidAutoWidget);

    // Create OpenAutoWorker and link everything up
    this->worker = new OpenAutoWorker([this](bool connected) {
        this->showAndroidAuto(connected);
    }, androidAutoWidget);
}

QWidget * OpenAutoFrame::createAndroidAutoWidget(QWidget * parent) {
    QWidget * widget = new QWidget(parent);
    widget->setGeometry(parent->geometry());
    widget->setAttribute(Qt::WA_AcceptTouchEvents);

    QGridLayout * layout = new QGridLayout(widget);
    layout->setMargin(0);

    layout->addWidget(new Widget::OpenAutoWidget());
    return widget;
}

QWidget * OpenAutoFrame::createConnectWidget(QWidget * parent) {
    // Layout everything vertically
    QWidget * widget = new QWidget(parent);
    QVBoxLayout * layout = new QVBoxLayout(widget);
    layout->setMargin(15);

    // Waiting section
    QWidget * waitingWidget = new QWidget();
    QVBoxLayout * waitingLayout = new QVBoxLayout(waitingWidget);
    waitingLayout->setMargin(0);
    waitingLayout->setSpacing(5);

    // Waiting for message
    QFont waitingFont = QFont("Rubik");
    waitingFont.setBold(true);
    waitingFont.setPointSize(20);

    QLabel * waitingLabel = new QLabel(" Waiting for device to connect...");
    waitingLabel->setFont(waitingFont);
    waitingLabel->setStyleSheet("color: white");
    waitingLayout->addStretch();
    waitingLayout->addWidget(waitingLabel, 0, Qt::AlignCenter);

    // Waiting animation
    QLabel * animationLabel = new QLabel();
    QMovie * animation = new QMovie(":/OpenAuto/animated/pulsing-circles.apng");        // TODO: Delete pointer when done
    animationLabel->setMovie(animation);
    animation->start();
    waitingLayout->addWidget(animationLabel, 0, Qt::AlignCenter);
    waitingLayout->addStretch();

    layout->addWidget(waitingWidget, 0, Qt::AlignHCenter);

    // Hint message
    // TODO: Change based on state
    QFont hintFont = QFont("Rubik");
    hintFont.setBold(true);
    hintFont.setPointSize(12);

    QWidget * hintWidget = new QWidget();
    QHBoxLayout * hintLayout = new QHBoxLayout(hintWidget);
    hintLayout->setMargin(0);
    hintLayout->setSpacing(waitingFont.pointSize()/4);

    QLabel * hintLabel = new QLabel("Wireless Android Auto is enabled, searching for");
    hintLabel->setFont(hintFont);
    hintLabel->setStyleSheet("color: darkgray");
    hintLayout->addWidget(hintLabel, 0, Qt::AlignLeft | Qt::AlignVCenter);

    QLabel * hintHighlightLabel = new QLabel("Jono's Pixel 7 Pro");
    hintHighlightLabel->setFont(hintFont);
    hintHighlightLabel->setStyleSheet("color: white");
    hintLayout->addWidget(hintHighlightLabel, 0, Qt::AlignRight | Qt::AlignVCenter);

    QGraphicsOpacityEffect * effect = new QGraphicsOpacityEffect(hintWidget);
    effect->setOpacity(0.4);
    hintWidget->setGraphicsEffect(effect);
    layout->addWidget(hintWidget, 0, Qt::AlignHCenter);

    return widget;
}

void OpenAutoFrame::showAndroidAuto(const bool show) {
    this->setCurrentIndex(show ? 1 : 0);
}
