#include <SoftwareSerial.h>

SoftwareSerial grbl(0,1); //set up RX, TX

void setup() {
  Serial.begin(115200); //initialize serial communication
  grbl.begin(115200); //initialize serial communication with the other Arduino
}

void loop() {
  //check if there is any data available on the serial port
  if (grbl.available() > 0) {
    //read the data from the serial port
    String gCode = grbl.readString();

    //print the g-code instructions to the serial monitor
    Serial.println(gCode);
  }
}
