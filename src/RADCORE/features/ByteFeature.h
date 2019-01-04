
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "../observers/Observer.h"
#include "../observers/FunctionObserver.h"
#include "../subjects/Subject.h"
#include "Feature.h"


namespace RAD {

  class ByteFeature : public Feature {
    
    private:

      typedef void (*FuncPtr)(uint8_t);

      Subject<uint8_t> _subject;
      uint8_t _data[1];

    public:
      
      ByteFeature(Device* device, const char* id, uint8_t featureFlags, uint8_t slaveConfig = 0)
        : Feature(BytePayload, device, id, featureFlags, slaveConfig) {
        _data[0] = 0;
        _payload.len = 1;
        _payload.data = _data;
      };

      void set(uint8_t value);
      uint8_t get();
      void watch(FuncPtr fx);
      Subject<uint8_t>* getSubject() { return &_subject; };

      void handlePayload(Payload* payload);

  };

}
