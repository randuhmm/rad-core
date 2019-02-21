
#pragma once

#include "./DeviceInterface.h"

namespace RAD {

  class I2CSlaveInterface: public DeviceInterface {


    public:

      void onSetup() = 0;
      void onUpdate() = 0;
      void handleEvent(Feature* feature, Event* event) = 0;

  };

}
