#include "FeatureConnector.h"

using namespace RAD;

FeatureConnector::FeatureConnector(Device* device): _device(device) {
  device->add(this);
};

Device* FeatureConnector::getDevice() {
  return _device;
}

Feature* FeatureConnector::getFeature(const char* id) {
  auto it = _features.begin();
  for(; it != _features.end(); it++) {
    if(strcmp((*it)->getId(), id) == 0) {
      return (*it);
    }
  }
  return nullptr;
}

void FeatureConnector::sendEvent(Feature* feature, Event* event) {
  return _device->handleEvent(feature, event);
}

void FeatureConnector::sendEvent(Event* event) {
  return _device->handleEvent(event);
}
