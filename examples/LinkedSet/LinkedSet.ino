#include <Arduino.h>
#include <RADCORE.h>


RAD::LinkedSet<uint8_t> mySet = RAD::LinkedSet<uint8_t>();


void setup() {
  mySet.add(1);
  mySet.add(2);
  mySet.add(3);
  mySet.add(4);
}

void loop() {

}