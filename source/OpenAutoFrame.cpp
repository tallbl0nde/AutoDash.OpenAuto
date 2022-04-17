#include <QGraphicsOpacityEffect>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMovie>

#include "OpenAutoFrame.hpp"
#include "widget/OpenAutoWidget.hpp"
#include "OpenAutoWorker.hpp"

OpenAutoFrame::OpenAutoFrame(QWidget * parent) : QWidget(parent) {
    // Create stacked widget to swap between connect message
    // and actual stream
    this->stack = new QStackedWidget();

    // Connect frame
    this->stack->addWidget(this->createConnectWidget(this->stack));

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

QWidget * OpenAutoFrame::createConnectWidget(QWidget * parent) {
    // Layout everything vertically
    QWidget * widget = new QWidget(parent);
    QVBoxLayout * layout = new QVBoxLayout(widget);
    layout->setMargin(10);

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

    QLabel * hintHighlightLabel = new QLabel("Jono's Galaxy Note10+");
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
    this->stack->setCurrentIndex(show ? 1 : 0);
}
