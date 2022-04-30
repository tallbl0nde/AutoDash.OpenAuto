#include "OpenAutoFrame.hpp"
#include "OpenAutoModule.hpp"
#include "Version.hpp"

OpenAutoModule::OpenAutoModule() : IModule() {

}

std::string OpenAutoModule::versionCompiledFor() {
    return AUTODASH_VERSION;
}

void OpenAutoModule::initialize(IResolver * resolver) {

}

IModule::Metadata OpenAutoModule::metadata() {
    return Metadata {
        "Android Auto",                             // Name
        "tallbl0nde",                               // Author
        ":/OpenAuto/icons/android-auto.svg",        // Icon
        "0.0.1"                                     // Version
    };
}

std::vector<ISettingEntry *> OpenAutoModule::settingEntries(ISettingEntryFactory * settingEntryFactory) {
    // TODO: Return actual settings
    return std::vector<ISettingEntry *>();
}

QWidget * OpenAutoModule::widget(QWidget * parent) {
     return new OpenAutoFrame(parent);
}

OpenAutoModule::~OpenAutoModule() {

}
