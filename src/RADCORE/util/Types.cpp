
#include "Types.h"

using namespace RAD;


PayloadType RAD::toPayloadType(const char* s) {
  PayloadType pt = VoidPayload;
  if(strcmp(s, "BinaryPayload") == 0) {
    pt = BinaryPayload;
  } else if(strcmp(s, "BytePayload") == 0) {
    pt = BytePayload;
  }
  return pt;
}


const char* RAD::fromPayloadType(PayloadType pt) {
  const char* s = "VoidPayload";
  if(pt == BinaryPayload) {
    s = "BinaryPayload";
  } else if(pt == BytePayload) {
    s = "BytePayload";
  }
  return s;
}


CommandType RAD::toCommandType(const char* s) {
  CommandType ct = VoidCommand;
  if(strcmp(s, "Get") == 0) {
    ct = Get;
  } else if(strcmp(s, "Set") == 0) {
    ct = Set;
  }
  return ct;
}


const char* RAD::fromCommandType(CommandType ct) {
  const char* s = "VoidCommand";
  if(ct == Get) {
    s = "Get";
  } else if(ct == Set) {
    s = "Set";
  }
  return s;
}


EventType RAD::toEventType(const char* s) {
  EventType et = VoidEvent;
  if(strcmp(s, "All") == 0) {
    et = All;
  } else if(strcmp(s, "Start") == 0) {
    et = Start;
  } else if(strcmp(s, "State") == 0) {
    et = State;
  }
  return et;
}


const char* RAD::fromEventType(EventType et) {
  const char* s = "VoidEvent";
  if(et == All) {
    s = "All";
  } else if(et == Start) {
    s = "Start";
  } else if(et == State) {
    s = "State";
  }
  return s;
}


Payload* RAD::buildPayload(bool data) {
  Payload* payload = new Payload();
  payload->type = BoolPayload;
  payload->len = 1;
  payload->data = (uint8_t*)malloc(payload->len * sizeof(uint8_t));
  if(data) {
    payload->data[0] = 255;
  } else {
    payload->data[0] = 0;
  }
  return payload;
}


Payload* RAD::buildPayload(uint8_t data) {
  Payload* payload = new Payload();
  payload->type = BytePayload;
  payload->len = 1;
  payload->data = (uint8_t*)malloc(payload->len * sizeof(uint8_t));
  payload->data[0] = data;
  return payload;
}


Payload* RAD::buildPayload(uint8_t* data, uint8_t len) {
  Payload* payload = new Payload();
  payload->type = BinaryPayload;
  payload->len = len;
  payload->data = data;
  return payload;
}


uint8_t RAD::packBinaryCommand(Command* command, uint8_t* data) {
  uint8_t id_len = strlen(command->feature_id);
  uint8_t payload_len = command->payload->len;
  uint8_t len = payload_len + id_len + 5;
  // version = 1
  data[0] = 1;
  // id length
  data[1] = id_len;
  // id
  memcpy(data[2], command->feature_id, id_len);
  // command->type
  data[2 + id_len] = command->type;
  // payload->type
  data[3 + id_len] = command->payload->type;
  // payload->len
  data[4 + id_len] = payload_len;
  if(payload_len != 0) {
    // payload->data
    memcpy(data[5 + id_len], command->payload->data, payload_len);
  }
  return len;
}


uint8_t RAD::packBinaryEvent(Event* event, uint8_t* data) {
  Serial.println(event->feature_id);
  uint8_t id_len = strlen(event->feature_id);
  uint8_t payload_len = event->payload->len;
  uint8_t len = payload_len + id_len + 5;
  // version = 1
  data[0] = 1;
  // id length
  Serial.print("id len = ");
  Serial.println(id_len, DEC);
  data[1] = id_len;
  // id
  memcpy(&data[2], event->feature_id, id_len);
  // event->type
  data[2 + id_len] = event->type;
  // payload->type
  data[3 + id_len] = event->payload->type;
  // payload->len
  data[4 + id_len] = payload_len;
  if(payload_len != 0) {
    // payload->data
    memcpy(&data[5 + id_len], event->payload->data, payload_len);
  }
  return len;
}


// Command* RAD::unpackBinaryCommand(uint8_t* data, uint8_t len) {
// }
// Event* RAD::unpackBinaryEvent(uint8_t* data, uint8_t len) {
// }

