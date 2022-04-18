#ifndef ANDROID_AUTO_INTERFACE_HPP
#define ANDROID_AUTO_INTERFACE_HPP

#include "openauto/Service/IAndroidAutoInterface.hpp"

class AndroidAutoInterface : public QObject, public openauto::service::IAndroidAutoInterface {
    Q_OBJECT

    public:
        // Constructs a new interface.
        AndroidAutoInterface();

        void mediaPlaybackUpdate(const aasdk::proto::messages::MediaInfoChannelPlaybackData& playback) override;
        void mediaMetadataUpdate(const aasdk::proto::messages::MediaInfoChannelMetadataData& metadata) override;
        void navigationStatusUpdate(const aasdk::proto::messages::NavigationStatus& navStatus) override;
        void navigationTurnEvent(const aasdk::proto::messages::NavigationTurnEvent& turnEvent) override;
        void navigationDistanceEvent(const aasdk::proto::messages::NavigationDistanceEvent& distanceEvent) override;

        // Destroys the interface.
        ~AndroidAutoInterface();
};

#endif