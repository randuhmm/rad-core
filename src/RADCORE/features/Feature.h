
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "../subjects/Subject.h"
#include "../observers/Observer.h"
#include "../devices/Device.h"

namespace RAD {

  // Forward declaration
  class Device;

  class Feature {

    
    private:

      Device* _device;
      const char* _id;
      uint8_t _featureFlags;

      bool _isSlave;
      uint8_t _slaveAddress;
      uint8_t _slaveId;
    
    protected:

      Payload _payload;
      Subject<Payload*> _payloadSubject;

    public:
      
      Feature(PayloadType payloadType, Device* device, const char* id, uint8_t featureFlags, uint8_t slaveConfig = 0);

      Device* getDevice() { return _device; };
      PayloadType getPayloadType() { return _payload.type; };
      const char* getId() { return _id; };

      bool checkFlag(uint8_t flag) { return _featureFlags & flag; };

      bool isSlave() { return _isSlave; };
      uint8_t getSlaveAddress() { return _slaveAddress; };
      uint8_t getSlaveId() { return _slaveId; };
      
      Payload* getPayload() { return &_payload; };
      Subject<Payload*>* getPayloadSubject() { return &_payloadSubject; };
      
      virtual void handlePayload(Payload* payload) = 0;

  };

}
