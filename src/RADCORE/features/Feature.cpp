#include "Feature.h"

using namespace RAD;

Feature::Feature(PayloadType payloadType, Device* device, const char* id, uint8_t featureFlags, uint8_t slaveConfig)
  : _device(device), _id(id), _featureFlags(featureFlags) {

  if(slaveConfig != 0) {
    _isSlave = true;
    _slaveAddress = (slaveConfig >> 4);
    _slaveId = (slaveConfig & 0xF);
  }

  _payload.type = payloadType;
  _payloadSubject.set(&_payload);

  _device->add(this);
}
