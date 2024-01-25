#include "DxlMaster.h"
const unsigned long dynamixel_baudrate = 57600;
const unsigned long serial_baudrate = 57600;
const uint8_t id = 21;
DynamixelDevice rgb(id);
void setup() {
DxlMaster.begin(dynamixel_baudrate);
rgb.init();
Serial.begin(serial_baudrate);
}
void loop() {
rgb.write(26, 255);
delay(1000);
rgb.write(27, 255);
delay(1000);
rgb.write(28, 255);
delay(1000);
rgb.write(26, 0);
delay(1000);
rgb.write(27, 0);
delay(1000);
rgb.write(28, 0);
delay(1000);
}
