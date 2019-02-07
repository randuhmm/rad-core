
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

      ByteFeature(const char* id, Device* device)
        : Feature(BytePayload, id, device) {
        _data[0] = 0;
        _state.len = 1;
        _state.data = _data;
      };

      void set(uint8_t value);
      uint8_t get();
      void watch(FuncPtr fx);
      Subject<uint8_t>* getSubject() { return &_subject; };

      void handleSet(Payload* payload);

  };

}
