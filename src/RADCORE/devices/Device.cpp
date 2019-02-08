#include "Device.h"

using namespace RAD;

void Device::add(Feature* feature) {
  if(!_setup) {
    _features.add(feature);
    new ObjectMethodObserver<Feature, Device, Event* >(feature, feature->getEventSubject(), this, &Device::handleEvent);
  }
}

void Device::add(DeviceInterface* interface) {
  if(!_setup) {
    _interfaces.add(interface);
  }
}

Feature* Device::getFeature(const char* id) {
  auto it = _features.begin();
  for(; it != _features.end(); it++) {
    if(strcmp((*it)->getId(), id) == 0) {
      return (*it);
    }
  }
  return nullptr;
}


void Device::setup() {
  if(_setup) return;
  _setup = true;
  auto interfaces_it = _interfaces.begin();
  for(;interfaces_it != _interfaces.end(); interfaces_it++) {
    (*interfaces_it)->onSetup();
  }
  auto connectors_it = _connectors.begin();
  for(;connectors_it != _connectors.end(); connectors_it++) {
    (*connectors_it)->onSetup();
  }
};

void Device::update() {
  if(_setup && _running) {
    auto interfaces_it = _interfaces.begin();
    for(;interfaces_it != _interfaces.end(); interfaces_it++) {
      (*interfaces_it)->onUpdate();
    }
    auto connectors_it = _connectors.begin();
    for(;connectors_it != _connectors.end(); connectors_it++) {
      (*connectors_it)->onUpdate();
    }
  }
};

void Device::handleEvent(Feature* feature, Event* event) {
  auto it = _interfaces.begin();
  for(;it != _interfaces.end(); it++) {
    (*it)->handleEvent(feature, event);
  }
}

Payload* Device::handleCommand(DeviceInterface* interface, Command* command) {
  Feature* feature = getFeature(command->feature_id);
  if(feature == nullptr) return nullptr;
  return feature->handleCommand(command);
}

Payload* Device::handleCommand(DeviceInterface* interface, Feature* feature, Command* command) {
  return feature->handleCommand(command);
}
