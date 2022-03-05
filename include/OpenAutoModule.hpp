#ifndef OPENAUTOMODULE_HPP
#define OPENAUTOMODULE_HPP

#include "interface/IModule.hpp"

// Unique identifier for module.
#define OPENAUTOMODULE_IID "tallbl0nde.AutoDash.OpenAutoModule"
#define OPENAUTOMODULE_JSON "OpenAutoModule.json"

// AutoDash module for OpenAuto integration.
class OpenAutoModule : public QObject, IModule {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID OPENAUTOMODULE_IID FILE OPENAUTOMODULE_JSON)
    Q_INTERFACES(IModule)

    public:
        // Constructs the module.
        OpenAutoModule();

        // Returns metadata for the module.
        Metadata metadata() override;

        // Returns the main widget for the module.
        QWidget * widget() override;

        // Destroys the module object.
        ~OpenAutoModule();
};

#endif
