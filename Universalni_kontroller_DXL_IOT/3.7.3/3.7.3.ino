#include "DxlMaster.h"
const unsigned long dynamixel_baudrate = 57600;
const unsigned long serial_baudrate = 57600;
const uint8_t idRGB = 21;
const uint8_t idBUT = 3;
uint8_t a;
DynamixelDevice rgb(idRGB);
DynamixelDevice but(idBUT);
void setup() {
DxlMaster.begin(dynamixel_baudrate);
rgb.init();
but.init();
Serial.begin(serial_baudrate);
}
void loop() {
but.read(27, a);
if (a==1){
rgb.write(26, 255);}
else rgb.write(26, 0);
}
