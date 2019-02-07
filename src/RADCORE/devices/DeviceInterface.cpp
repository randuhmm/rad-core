#include "DeviceInterface.h"

using namespace RAD;

DeviceInterface::DeviceInterface(Device* device): _device(device) {
  device->add(this);
};

Device* DeviceInterface::getDevice() {
  return _device;
}

Feature* DeviceInterface::getFeature(const char* name) {
  return _device->getFeature(name);
}

LinkedSet<Feature*>* DeviceInterface::getFeatures() {
  return _device->getFeatures();
}

Payload* DeviceInterface::sendCommand(Feature* feature, Command* command) {
  return _device->handleCommand(this, feature, command);
}

Payload* DeviceInterface::sendCommand(Command* command) {
  return _device->handleCommand(this, command);
}
