#include "widget/OpenAutoWidget.hpp"

namespace Widget {
    OpenAutoWidget::OpenAutoWidget(QWidget * parent) : QWidget(parent) {
        this->setAttribute(Qt::WA_AcceptTouchEvents);
    }
};
