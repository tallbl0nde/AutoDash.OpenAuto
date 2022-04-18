#include "AndroidAutoInterface.hpp"

AndroidAutoInterface::AndroidAutoInterface() : QObject() {

}

void AndroidAutoInterface::mediaPlaybackUpdate(const aasdk::proto::messages::MediaInfoChannelPlaybackData& playback) {
    // TODO: Implement
}

void AndroidAutoInterface::mediaMetadataUpdate(const aasdk::proto::messages::MediaInfoChannelMetadataData& metadata) {
    // TODO: Implement
}

void AndroidAutoInterface::navigationStatusUpdate(const aasdk::proto::messages::NavigationStatus& navStatus) {
    // TODO: Implement
}

void AndroidAutoInterface::navigationTurnEvent(const aasdk::proto::messages::NavigationTurnEvent& turnEvent) {
    // TODO: Implement
}

void AndroidAutoInterface::navigationDistanceEvent(const aasdk::proto::messages::NavigationDistanceEvent& distanceEvent) {
    // TODO: Implement
}

AndroidAutoInterface::~AndroidAutoInterface() {

}