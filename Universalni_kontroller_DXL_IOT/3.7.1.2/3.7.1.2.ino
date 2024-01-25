#include "DxlMaster2.h"
// Выставление скорости передачи данных, ID устройств
#define BAUDRATE 1000000
#define DXL_ID 3
const float DXL_PROTOCOL_VERSION = 2.0;
int16_t speed = 1000;
float degree_coeff = 16383.0 / 360;
DynamixelMotor motor(DXL_ID);
void setup() {
  DxlMaster.begin(BAUDRATE);
  motor.protocolVersion(DXL_PROTOCOL_VERSION);
  delay(100);

  uint8_t status = motor.init();
  if (status != DYN_STATUS_OK)
  {
    while (1);
  }
  motor.enableTorque(0);  // отключаем крутящий момент, когда изменяем EEPROM область в сервоприводе
  motor.write(11, (uint8_t)3); // установка режима работы сервопривода в качестве шарнира = 3
  motor.write(112, (uint32_t)speed); // установка скорости передвижения сервопривода
  delay(1000);
}
void loop() {
  motor.enableTorque(1);
  // перемещение в середину диапазона 0...360

  motor.write(116, (uint32_t)(180 * degree_coeff));
  delay(2000);
  // на 45° против часовой стрелки
  motor.write(116, (uint32_t)((180 + 45) * degree_coeff));
  delay(2000);
  // перемещение в середину
  motor.write(116, (uint32_t)(180 * degree_coeff));
  delay(2000);
  // на 45° по часовой стрелке
  motor.write(116, (uint32_t)((180 - 45) * degree_coeff));
  delay(2000);
 
}
