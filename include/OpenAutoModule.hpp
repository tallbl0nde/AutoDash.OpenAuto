#ifndef OPENAUTOMODULE_HPP
#define OPENAUTOMODULE_HPP

#include "interface/IModule.hpp"

// Unique identifier for module.
#define OPENAUTOMODULE_IID "tallbl0nde.AutoDash.OpenAutoModule"

// AutoDash module for OpenAuto integration.
class OpenAutoModule : public QObject, IModule {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID OPENAUTOMODULE_IID)
    Q_INTERFACES(IModule)

    public:
        // Constructs the module.
        OpenAutoModule();

        // Implement IModule.
        std::string versionCompiledFor() override;
        void initialize(IResolver * resolver) override;
        Metadata metadata() override;
        std::vector<ISettingEntry *> settingEntries(ISettingEntryFactory * settingEntryFactory) override;
        QWidget * widget(QWidget * parent = nullptr) override;

        // Destroys the module object.
        ~OpenAutoModule();
};

#endif
