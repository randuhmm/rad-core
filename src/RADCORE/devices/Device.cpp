#include "Device.h"

using namespace RAD;

void Device::add(Feature* feature) {
  if(!_setup) {
    _features.add(feature);
    new ObjectMethodObserver<Feature, Device, Payload*>(feature, feature->getPayloadSubject(), this, &Device::onPayload);
  }
}


Feature* Device::getFeature(const char* id) {
  Node<Feature* >* temp = _features.head;
  while(temp != NULL) {
    if(strcmp(temp->data->getId(), id) == 0) {
      return temp->data;
    }
    temp = temp->next;
  }
  return NULL;
}
