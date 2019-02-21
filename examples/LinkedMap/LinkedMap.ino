#include <Arduino.h>
#include <RADCORE.h>


RAD::LinkedMap<const char*, uint8_t> myMap = RAD::LinkedMap<const char*, uint8_t>();


void print() {
  auto it = myMap.begin();
  Serial.print("Map size = ");
  Serial.println(myMap.size());
  Serial.print("Map contains: ");
  for(;it != myMap.end(); it++) {
    Serial.print((*it)->key);
    Serial.print("=");
    Serial.print((*it)->value);
    Serial.print(" ");
  }
  Serial.println("");
}

bool checkPresent(const char* key, uint8_t value) {
  Serial.print("Check if map contains ");
  Serial.print(key);
  Serial.print("... ");
  if(myMap.contains(key)) {
    if((*myMap.value(key)) == value) {
      Serial.println("Success - found key and value");
      return true;
    } else {
      Serial.println("Failure - key with wrong value!!");
    }
  } else {
    Serial.println("Failure - key not found!!");
  }
  return false;
}

bool checkMissing(const char* key) {
  Serial.print("Check if map does not contain ");
  Serial.print(key);
  Serial.print("... ");
  if(!myMap.contains(key)) {
    Serial.println("Success - item not found");
    return true;
  } else {
    Serial.println("Failure - item found!!");
    return false;
  }
}


void setup() {

  Serial.begin(9600);
  Serial.println("Starting...");
  delay(1000);

  Serial.println("Adding 'a', 'b' and 'c' to the map...");
  myMap.set("a", 1);
  myMap.set("b", 2);
  myMap.set("c", 3);
  print();

  Serial.println("Adding 'd' to the map...");
  myMap.set("d", 4);
  print();

  checkPresent("a", 1);
  checkPresent("b", 2);
  checkPresent("c", 3);
  checkPresent("d", 4);
  checkMissing("e");
  checkMissing("f");
  checkMissing("g");
  checkMissing("h");

  Serial.println("Removing 'c' from the map...");
  myMap.remove("c");
  print();

  checkPresent("a", 1);
  checkPresent("b", 2);
  checkMissing("c");
  checkPresent("d", 4);
  checkMissing("e");
  checkMissing("f");
  checkMissing("g");
  checkMissing("h");

  Serial.println("Removing 'a' from the map...");
  myMap.remove("a");
  print();

  checkMissing("a");
  checkPresent("b", 2);
  checkMissing("c");
  checkPresent("d", 4);
  checkMissing("e");
  checkMissing("f");
  checkMissing("g");
  checkMissing("h");

  Serial.println("Adding 'h' to the map...");
  myMap.set("h", 0);
  print();

  checkMissing("a");
  checkPresent("b", 2);
  checkMissing("c");
  checkPresent("d", 4);
  checkMissing("e");
  checkMissing("f");
  checkMissing("g");
  checkPresent("h", 0);

  Serial.println("Removing 'h', 'd' and 'b' from the map...");
  myMap.remove("h");
  myMap.remove("d");
  myMap.remove("b");
  print();

  if(myMap.size() != 0) {
    Serial.println("Failure - map is not empty!");
  }

}

void loop() {

}