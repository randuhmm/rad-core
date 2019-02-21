
#pragma once

#include "../util/Types.h"
#include "../subjects/Subject.h"
#include "../Device.h"
#include "../features/Feature.h"

namespace RAD {

  class Device;
  class Feature;

  class FeatureConnector {

      LinkedSet<Feature* > _features;
      Device* _device;

    public:

      FeatureConnector(Device* device);
      Device* getDevice();
      Feature* getFeature(const char* name);

      virtual void onSetup() = 0;
      virtual void onUpdate() = 0;
      virtual void handleCommand(Feature* feature, Command* command) = 0;

  };

}
