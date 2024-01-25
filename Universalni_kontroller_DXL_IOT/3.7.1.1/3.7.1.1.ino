#include "DxlMaster2.h"
// ID сервопривода
const uint8_t id = 1;
// скорость, от 0 до 1023
int16_t speed = 512;
const float DXL_PROTOCOL_VERSION = 2.0; 
// скорость соединения
const long unsigned int baudrate = 1000000;
DynamixelMotor motor(id);
void setup()
{
DxlMaster.begin(baudrate);
motor.protocolVersion(DXL_PROTOCOL_VERSION); 
delay(100);
// ожидание статуса сервопривода
uint8_t status = motor.init();
if(status != DYN_STATUS_OK)
{
while(1);
}
motor.enableTorque();
motor.write(11, (uint8_t)3);
// установка режима joint с углом поворота 300°
// see doc to compute angle values
//motor.jointMode(0, 1024);
motor.write(52, (uint32_t)0);
motor.write(48, (uint32_t)2);
motor.speed(speed);
}
void loop()
{
// установка средней позиции
motor.write(116, (uint32_t)(512*16));
delay(500);
// поворот на 45° против часовой стрелки
motor.write(116, (uint32_t)(666*16));
delay(500);
// установкка средней позиции
motor.write(116, (uint32_t)(512*16));
delay(500);
// поворот на 45° по часовой стрелке
motor.write(116, (uint32_t)(358*16));
delay(500);
}
