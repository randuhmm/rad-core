
#pragma once

#include "../util/Types.h"
#include "../subjects/Subject.h"
#include "./Feature.h"

namespace RAD {

  class Feature;

  class FeatureConnector {

      LinkedSet<Feature* > _features;

    public:

      virtual void onSetup() = 0;
      virtual void onUpdate() = 0;
      virtual void handleCommand(Feature* feature, Command* command) = 0;

  };

}
