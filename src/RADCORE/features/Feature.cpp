#include "Feature.h"

using namespace RAD;

Feature::Feature(PayloadType payloadType, const char* id, Device* device,
                 FeatureConnector* connector)
  : _id(id), _connector(connector) {
  _state.type = payloadType;
  _event.feature_id = id;
  _event.payload = &_state;
  _eventSubject.set(&_event);
  device->add(this);
}

Payload* Feature::handleCommand(Command* command) {
  if(_connector != nullptr) {
    _connector->handleCommand(this, command);
  }
  switch(command->type) {
    case CommandType::Set :
      handleSet(command->payload);
      break;
    case CommandType::Get :
      return &_state;
      break;
  }
  return nullptr;
}
