
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

      BoolFeature(const char* id, Device* device)
        : Feature(BoolPayload, id, device) {
        _data[0] = 0;
        _state.len = 1;
        _state.data = _data;
      };

      void set(bool value);
      bool get();
      void watch(FuncPtr fx);
      Subject<bool>* getSubject() { return &_subject; };

      void handleSet(Payload* payload);

  };

}
