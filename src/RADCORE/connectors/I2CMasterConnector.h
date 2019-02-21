
#pragma once

#include "../util/Types.h"
#include "../util/LinkedMap.h"
#include "../util/I2C.h"
#include "../subjects/Subject.h"
#include "./FeatureConnector.h"

namespace RAD {

  class I2CMasterConnector: public FeatureConnector {

    private:

      //LinkedMap<Feature*, I2CConfig> _config;

    public:

      void setConfig(Feature* feature, uint8_t slaveAddr, uint8_t featureAddr);
      void onSetup();
      void onUpdate();
      void handleCommand(Feature* feature, Command* command);

  };

}
