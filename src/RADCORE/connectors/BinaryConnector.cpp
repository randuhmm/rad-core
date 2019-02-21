#include "BinaryConnector.h"

using namespace RAD;

void BinaryConnector::handleCommand(Feature* feature, Command* command) {
    uint8_t len = packBinaryCommand(command, _data);
    sendCommandData(_data, len);
}
