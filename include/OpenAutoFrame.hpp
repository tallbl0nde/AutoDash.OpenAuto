#ifndef OPENAUTOFRAME_HPP
#define OPENAUTOFRAME_HPP

#include <QStackedWidget>

class OpenAutoWorker;

// Main frame for displaying OpenAuto (both video and other widgets)
class OpenAutoFrame : public QStackedWidget {
    Q_OBJECT

    private:
        // OpenAuto worker class.
        OpenAutoWorker * worker;

        // Helper to create the android auto widget.
        QWidget * createAndroidAutoWidget(QWidget * parent);

        // Helper to create the waiting to connect widget.
        QWidget * createConnectWidget(QWidget * parent);

    public:
        // Constructs the frame.
        OpenAutoFrame(QWidget * = nullptr);

        // Toggles between displaying connect message and android auto.
        void showAndroidAuto(const bool);
};

#endif
