
#pragma once

#include "../util/Types.h"
#include "../util/LinkedMap.h"
#include "../util/I2C.h"
#include "../subjects/Subject.h"
#include "./FeatureConnector.h"

namespace RAD {

  class BinaryConnector: public FeatureConnector {

    private:

      uint8_t _data[RAD_MAX_BINARY_DATA_SIZE];

    public:

      void handleCommand(Feature* feature, Command* command);
      virtual void onSetup() = 0;
      virtual void onUpdate() = 0;
      virtual void sendCommandData(uint8_t* data, uint8_t len) = 0;
  };

}
