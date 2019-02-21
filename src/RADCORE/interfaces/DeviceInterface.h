
#pragma once

#include "../Device.h"
#include "../util/Types.h"
#include "../util/LinkedSet.h"
#include "../subjects/Subject.h"
#include "../features/Feature.h"

namespace RAD {

  class Device;
  class Feature;

  class DeviceInterface {

    private:

      Device* _device;

    public:

      DeviceInterface(Device* device);
      Device* getDevice();
      Feature* getFeature(const char* id);
      LinkedSet<Feature*>* getFeatures();
      Payload* sendCommand(Feature* feature, Command* command);
      Payload* sendCommand(Command* command);

      virtual void onSetup() = 0;
      virtual void onUpdate() = 0;
      virtual void handleEvent(Feature* feature, Event* event) = 0;

  };

}
