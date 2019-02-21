#include <Arduino.h>
#include <RADCORE.h>


String inString = "";    // string to hold input

class MySerialInterface : public RAD::DeviceInterface {

    const char* _featureId;

  public:

    MySerialInterface(RAD::Device* device, const char* featureId):
      DeviceInterface(device), _featureId(featureId) {};

    void onSetup() {
        Serial.println("MySerialInterface::onSetup");
    };

    void onUpdate() {
      Serial.println("MySerialInterface::onUpdate");

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

          RAD::Command inputCmd;
          inputCmd.feature_id = _featureId;
          inputCmd.payload = &inputPayload;
          inputCmd.type = RAD::CommandType::Set;

          getDevice()->handleCommand(this, &inputCmd);

          // clear the string for new input:
          inString = "";
        }
      }

    };

    void handleEvent(RAD::Feature* feature, RAD::Event* event) {
        Serial.println("MySerialInterface::handleEvent");
        Serial.print("feature = ");
        Serial.println(feature->getId());
        Serial.print("Payload = ");
        Serial.println(event->payload->data[0]);
    };

};

const char* deviceName = "MyDevice";
const char* featureId = "switch1";
RAD::Device device = RAD::Device(deviceName);
MySerialInterface serialInterface = MySerialInterface(&device, featureId);
RAD::BoolFeature switch1 = RAD::BoolFeature(featureId, &device);

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
