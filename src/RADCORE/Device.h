
#pragma once

#include "./interfaces/DeviceInterface.h"
#include "./util/LinkedSet.h"
#include "./features/Feature.h"
#include "./connectors/FeatureConnector.h"
#include "./observers/ObjectMethodObserver.h"

namespace RAD {

  class DeviceInterface;
  class FeatureConnector;

  class Device {

    private:

      LinkedSet<DeviceInterface*> _interfaces;
      LinkedSet<FeatureConnector*> _connectors;
      LinkedSet<Feature* > _features;

      const char* _name;

      bool _setup = false;
      bool _running = true;


    public:

      Device(const char* name) : _name(name) {};

      void setup();
      void update();
      void add(DeviceInterface* interface);
      void add(Feature* feature);
      //void add(FeatureConnector* _connector);

      const char* getName() { return _name; };
      LinkedSet<Feature* >* getFeatures() { return &_features; };
      Feature* getFeature(const char* id);

      void handleEvent(Feature* feature, Event* event);
      Payload* handleCommand(DeviceInterface* interface, Command* command);
      Payload* handleCommand(DeviceInterface* interface, Feature* feature, Command* command);

  };

}
