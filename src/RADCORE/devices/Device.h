
#pragma once

#include "../util/LinkedSet.h"
#include "../features/Feature.h"
#include "../observers/ObjectMethodObserver.h"

namespace RAD {

  class Feature;

  class Device {

    private:

      LinkedSet<Feature* > _features;
      const char* _name;
      bool _setup = false;
      bool _running = true;
  
    public:

      Device(const char* name) : _name(name) {};

      void add(Feature* feature);

      void setup() {
        _setup = true;
        onSetup();
      };

      void update() {
        if(_setup && _running) {
          onUpdate();
        }
      };

      Feature* getFeature(const char* id);
      Feature* getAt(uint8_t index) { return _features.get(index); };

      virtual void onSetup() = 0;
      virtual void onUpdate() = 0;
      virtual void onPayload(Feature* feature, Payload* payload) = 0;
    
  };

}
