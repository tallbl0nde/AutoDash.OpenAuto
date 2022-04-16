#include "OpenAutoFrame.hpp"
#include "OpenAutoModule.hpp"

OpenAutoModule::OpenAutoModule() : IModule() {

}

IModule::Metadata OpenAutoModule::metadata() {
    return Metadata {
        "Android Auto",                             // Name
        "tallbl0nde",                               // Author
        ":/OpenAuto/icons/android-auto.svg",        // Icon
        "0.0.1"                                     // Version
    };
}

QWidget * OpenAutoModule::widget() {
     return new OpenAutoFrame();
}

OpenAutoModule::~OpenAutoModule() {

}
