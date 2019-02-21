#include <Arduino.h>
#include <RADCORE.h>


void myCallback(uint8_t value) {
  Serial.print("myCallback: value = ");
  Serial.println(value);
}


RAD::Subject<uint8_t> mySubject = RAD::Subject<uint8_t>();
RAD::FunctionObserver<uint8_t> myObserver = RAD::FunctionObserver<uint8_t>(&mySubject, myCallback);

uint8_t value = 0;


void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println("Starting...");
}

void loop() {
  delay(1000);
  mySubject.set(value);
  mySubject.notify();
  value++;
}
