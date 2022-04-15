QT += bluetooth multimedia multimediawidgets widgets

TARGET = $$qtLibraryTarget(OpenAutoModule)
TEMPLATE = lib
DESTDIR = $$PWD/module
CONFIG += plugin
LIBS += -lusb-1.0 -laasdk -lopenauto

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

RESOURCES += resources/resources.qrc

INCLUDEPATH += \
    /usr/include/libusb-1.0/ \
    $$PWD/include \
    $$PWD/../../include

SOURCES += \
    $$files(source/*.cpp, true) \

HEADERS += \
    $$files(include/*.hpp, true) \
    $$PWD/../../include/interface/IModule.hpp
