#include "BoolFeature.h"

using namespace RAD;

void BoolFeature::set(bool value) {
  _subject.set(value);
  _subject.notify();
  _data[0] = (uint8_t)value;
  _payloadSubject.notify();
}


bool BoolFeature::get() {
  return _subject.get();
}


void BoolFeature::watch(FuncPtr fx) {
  new FunctionObserver<bool>(getSubject(), fx);
}


void BoolFeature::handlePayload(Payload* payload) {
  uint8_t value = payload->data[0];
  _payload.data[0] = value;
  _subject.set(value);
  _subject.notify();
}
