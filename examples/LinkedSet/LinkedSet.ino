#include <Arduino.h>
#include <RADCORE.h>


RAD::LinkedSet<uint8_t> mySet = RAD::LinkedSet<uint8_t>();


void print() {
  auto it = mySet.begin();
  Serial.print("Set size = ");
  Serial.println(mySet.size());
  Serial.print("Set contains: ");
  for(;it != mySet.end(); it++) {
    Serial.print((*it));
    Serial.print(" ");
  }
  Serial.println("");
}

void checkPresent(uint8_t value) {
  Serial.print("Check if set contains ");
  Serial.print(value);
  Serial.print("... ");
  if(mySet.contains(value)) {
    Serial.println("Success - found item");
  } else {
    Serial.println("Failure - item not found!!");
  }
}

void checkMissing(uint8_t value) {
  Serial.print("Check if set does not contain ");
  Serial.print(value);
  Serial.print("... ");
  if(!mySet.contains(value)) {
    Serial.println("Success - item not found");
  } else {
    Serial.println("Failure - item found!!");
  }
}


void setup() {

  Serial.begin(9600);
  Serial.println("Starting...");
  delay(1000);

  Serial.println("Adding 1, 2 and 3 to the set...");
  mySet.add(1);
  mySet.add(2);
  mySet.add(3);
  print();

  Serial.println("Adding 4 to the set...");
  mySet.add(4);
  print();

  checkPresent(1);
  checkPresent(2);
  checkPresent(3);
  checkPresent(4);
  checkMissing(5);
  checkMissing(6);
  checkMissing(7);
  checkMissing(0);

  Serial.println("Removing 3 from the set...");
  mySet.remove(3);
  print();

  checkPresent(1);
  checkPresent(2);
  checkMissing(3);
  checkPresent(4);
  checkMissing(5);
  checkMissing(6);
  checkMissing(7);
  checkMissing(0);

  Serial.println("Removing 1 from the set...");
  mySet.remove(1);
  print();

  checkMissing(1);
  checkPresent(2);
  checkMissing(3);
  checkPresent(4);
  checkMissing(5);
  checkMissing(6);
  checkMissing(7);
  checkMissing(0);

  Serial.println("Adding 0 to the set...");
  mySet.add(0);
  print();

  checkMissing(1);
  checkPresent(2);
  checkMissing(3);
  checkPresent(4);
  checkMissing(5);
  checkMissing(6);
  checkMissing(7);
  checkPresent(0);

  Serial.println("Removing 0, 4 and 2 from the set...");
  mySet.remove(0);
  mySet.remove(4);
  mySet.remove(2);
  print();

  if(mySet.size() != 0) {
    Serial.println("Failure - set is not empty!");
  }

}

void loop() {

}