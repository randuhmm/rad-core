
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "../observers/Observer.h"
#include "../observers/FunctionObserver.h"
#include "../subjects/Subject.h"
#include "Feature.h"


namespace RAD {

  class BoolFeature : public Feature {
    
    private:

      typedef void (*FuncPtr)(bool);

      Subject<bool> _subject;
      uint8_t _data[1];

    public:
      
      BoolFeature(Device* device, const char* id, uint8_t featureFlags, uint8_t slaveConfig = 0)
        : Feature(BoolPayload, device, id, featureFlags, slaveConfig) {
        _data[0] = 0;
        _payload.len = 1;
        _payload.data = _data;
      };

      void set(bool value);
      bool get();
      bool watch(FuncPtr fx);
      Subject<bool>* getSubject() { return &_subject; };

      void handlePayload(Payload* payload);

  };

}
