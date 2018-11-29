#include <Arduino.h>
#include <RADCORE.h>


String inString = "";    // string to hold input

class MyDevice : public RAD::Device {

  public:

    MyDevice(const char* name): Device(name) {};

    void onSetup() {
        Serial.println("MyDevice::onSetup");
    };

    void onUpdate() {
      Serial.println("MyDevice::onUpdate");

      while (Serial.available() > 0) {
        int inChar = Serial.read();
        if (isDigit(inChar)) {
          // convert the incoming byte to a char and add it to the string:
          inString += (char)inChar;
        }
        // if you get a newline, print the string, then the string's value:
        if (inChar == '\n') {
          Serial.print("Value: ");
          Serial.println(inString.toInt());
          Serial.print("String: ");
          Serial.println(inString);
          RAD::Payload inputPayload;
          uint8_t inputData[1];
          inputData[0] = (uint8_t)inString.toInt();
          inputPayload.type = RAD::PayloadType::BytePayload;
          inputPayload.len = 1;
          inputPayload.data = inputData;
          getAt(0)->handlePayload(&inputPayload);
          // clear the string for new input:
          inString = "";
        }
      }

    };

    void onPayload(RAD::Feature* feature, RAD::Payload* payload) {
        Serial.println("MyDevice::onPayload");
        Serial.print("feature = ");
        Serial.println(feature->getId());
        Serial.print("Payload = ");
        Serial.println(payload->data[0]);
    };

};


const char* name = "MyDevice";
MyDevice device = MyDevice(name);
RAD::BoolFeature switch1 = RAD::BoolFeature(&device, "switch1", 0);

void myCallback(bool value) {
  Serial.print("myCallback: value = ");
  Serial.println(value);
}

void setup() {
  delay(1000);
  switch1.watch(myCallback);
  Serial.begin(9600);
  Serial.println("Starting...");
  device.setup();
}

void loop() {
  bool value = switch1.get();
  switch1.set(!value);
  delay(5000);
  device.update();
  delay(5000);
}
