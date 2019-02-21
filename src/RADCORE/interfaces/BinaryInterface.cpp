#include "BinaryInterface.h"

using namespace RAD;

void BinaryInterface::handleEvent(Feature* feature, Event* event) {
    uint8_t len = packBinaryEvent(event, _data);
    sendEventData(_data, len);
}
