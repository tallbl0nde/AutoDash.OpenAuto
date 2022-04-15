#ifndef OPENAUTOFRAME_HPP
#define OPENAUTOFRAME_HPP

#include <QStackedWidget>
#include <QWidget>

class OpenAutoWorker;

// Main frame for displaying OpenAuto (both video and other widgets)
class OpenAutoFrame : public QWidget {
    Q_OBJECT

    private:
        // Stacked widget to swap between android auto and connect message.
        QStackedWidget * stack;

        // OpenAuto worker class.
        OpenAutoWorker * worker;

    public:
        // Constructs the frame.
        OpenAutoFrame(QWidget * = nullptr);

        // Toggles between displaying connect message and android auto.
        void showAndroidAuto(const bool);
};

#endif
