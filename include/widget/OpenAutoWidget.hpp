#ifndef WIDGET_OPENAUTOWIDGET_HPP
#define WIDGET_OPENAUTOWIDGET_HPP

#include <QWidget>

namespace Widget {
    class OpenAutoWidget : public QWidget {
        Q_OBJECT

        public:
            // Constructs a new OpenAutoWidget.
            OpenAutoWidget(QWidget * = nullptr);
    };
};

#endif
