
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "DeviceInterface.h"

namespace RAD {

  class BinaryInterface : public DeviceInterface {

    private:

      uint8_t _data[RAD_MAX_BINARY_DATA_SIZE];

    public:

      BinaryInterface(RAD::Device* device):
        DeviceInterface(device) {};

      void handleEvent(Feature* feature, Event* event);
      virtual void onSetup() = 0;
      virtual void onUpdate() = 0;
      virtual void sendEventData(uint8_t* data, uint8_t len) = 0;

  };

}
