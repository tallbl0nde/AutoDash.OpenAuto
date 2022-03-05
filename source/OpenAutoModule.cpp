#include "OpenAutoModule.hpp"
#include <QWidget>

OpenAutoModule::OpenAutoModule() : IModule() {

}

IModule::Metadata OpenAutoModule::metadata() {
    return Metadata {
        "Android Auto",                                         // Name
        "tallbl0nde",                                           // Author
        "/home/jonathon/AutoDash/modules/openauto/resources/icons/android-auto.svg",     // Icon
        "0.0.1"                                                 // Version
    };
}

QWidget * OpenAutoModule::widget() {
    return new QWidget();
}

OpenAutoModule::~OpenAutoModule() {

}
