#include "ByteFeature.h"

using namespace RAD;

void ByteFeature::set(uint8_t value) {
  _subject.set(value);
  _subject.notify();
  _data[0] = (uint8_t)value;
  _eventSubject.notify();
}


uint8_t ByteFeature::get() {
  return _subject.get();
}


void ByteFeature::watch(FuncPtr fx) {
  new FunctionObserver<uint8_t>(getSubject(), fx);
}


void ByteFeature::handleSet(Payload* payload) {
  uint8_t value = payload->data[0];
  _state.data[0] = value;
  _subject.set(value);
  _subject.notify();
}
