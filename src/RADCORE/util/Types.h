
#pragma once

#include <Arduino.h>

namespace RAD {


  // Payload Types
  enum PayloadType {
    VoidPayload      = 0x0,
    BoolPayload      = 0x1,
    BytePayload      = 0x2,
    WordPayload      = 0x4,
    DWordPayload     = 0x8,
    QWordPayload     = 0x10,
    BinaryPayload    = 0x20
  };

  // Command Types
  enum CommandType {
    VoidCommand  = 0x0,
    Get          = 0x1,
    Set          = 0x2,
    Trigger      = 0x4
  };

  // Event Types
  enum EventType {
    VoidEvent  = 0x0,
    All        = 0x1,
    Start      = 0x2,
    State      = 0x4
  };

  // 8-bit Integer Definition
  typedef unsigned char uint8_t;

  // Payload Struct Definition
  struct Payload {
    PayloadType type;
    uint8_t len;
    uint8_t* data;
  };

  struct Command {
    const char* feature_id;
    CommandType type;
    Payload* payload;
  };

  struct Event {
    const char* feature_id;
    EventType type;
    Payload* payload;
  };

  PayloadType toPayloadType(const char* s);
  const char* fromPayloadType(PayloadType ft);
  CommandType toCommandType(const char* s);
  const char* fromCommandType(CommandType ct);
  EventType toEventType(const char* s);
  const char* fromEventType(EventType et);

  Payload* buildPayload(bool data);
  Payload* buildPayload(uint8_t data);
  Payload* buildPayload(uint8_t* data, uint8_t len);

}
