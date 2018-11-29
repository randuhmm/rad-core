
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
    NullCommand  = 0x0,
    Get          = 0x1,
    Set          = 0x2,
    Trigger      = 0x4
  };

  // Event Types
  enum EventType {
    NullEvent  = 0x0,
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

}
