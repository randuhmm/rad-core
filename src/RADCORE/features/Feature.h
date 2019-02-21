
#pragma once

#include "../util/Defines.h"
#include "../util/Types.h"
#include "../subjects/Subject.h"
#include "../observers/Observer.h"
#include "../connectors/FeatureConnector.h"
#include "../Device.h"

namespace RAD {

  class Device;
  class FeatureConnector;

  class Feature {

    private:

      const char* _id;

    protected:

      Payload _state;
      Event _event;
      Subject<Event*> _eventSubject;
      FeatureConnector* _connector;

      virtual void handleSet(Payload* payload) = 0;

    public:

      Feature(PayloadType payloadType, const char* id, Device* device,
              FeatureConnector* featureconnector = NULL);

      PayloadType getPayloadType() { return _state.type; };
      const char* getId() { return _id; };

      Payload* getState() { return &_state; };
      Event* getEvent() { return &_event; };
      Subject<Event*>* getEventSubject() { return &_eventSubject; };

      Payload* handleCommand(Command* command);

  };

}
