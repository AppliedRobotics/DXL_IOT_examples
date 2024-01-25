#include <SPI.h> 
#include <Ethernet.h> 
#include <DxlMaster2.h>
const uint8_t id = 1;
const uint8_t id1 = 3;
int16_t speed = 512;
const long unsigned int baudrate = 1000000;
DynamixelMotor motor(id);
DynamixelMotor motor1(id1);
boolean newInfo = 0; 
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80); 
void setup() {
Ethernet.begin (mac, ip);
Serial.begin (1000000);
server. begin();
 DxlMaster.begin(baudrate);
  delay(100);
  uint8_t status = motor.init();
  motor.protocolVersion(2.0);
  motor.enableTorque(0); 
  motor.write(DYN2_ADDR_OPERATION_MODE, (uint8_t)1); 
  motor.enableTorque(1); 
  
  motor1.protocolVersion(2.0);
  motor1.enableTorque(0); 
  motor1.write(DYN2_ADDR_OPERATION_MODE, (uint8_t)1); 
  motor1.enableTorque(1); 
}
void loop() {
EthernetClient client = server.available(); 
if (client){ 
boolean currentLineIsBlank = true;
while (client.connected()) { 
if (client.available()) { 
char c = client.read(); 
if (newInfo && c == ' '){
newInfo = 0; 
}
if (c == '$'){
newInfo = 1;
}
if (newInfo == 1){ 
Serial.println (c);
if (c == '1'){ 
Serial.println ("Вперед");
speed =100;
motor.speed(speed);
motor1.speed(-1 * speed);
}
if (c == '2'){
Serial.println ("Разворот");
speed =-100;
motor.speed(speed);
motor1.speed(speed);
}
if (c == '3'){ 
Serial.println ("Стоп");
speed =0;
motor.speed(speed);
motor1.speed(speed);
}
}
if (c == '\n') { 
currentLineIsBlank = true; 
}
else if (c != '\r') {
currentLineIsBlank = false; 
}
if (c == '\n' && currentLineIsBlank) { 
client. println ("HTTP/1.1 200 OK"); 
client. println ("Content-Type: text/html");
client. println ("Connection: close");
client. println ("Refresh: 5"); 
client. println ();
client. println ("<!DOCTYPE HTML>"); 
client. println ("<html>"); 
client. println ("<head>");
client. println ("<meta http-equiv=’Content-Type’ content=’text/html ; charset=utf-8’/>");
client. print ("<title>IoT Web Server</title>"); 
client. println ("</head>"); 
client. println ("<body>");
client. print ("<H1>IoT Web Server</H1>"); 
client. print ("<a href=\"/$1\"><button>Прямо</button></a>");
client. print ("<a href=\"/$2\"><button>Разворот</button></a>");
client. print ("<a href=\"/$3\"><button>Стоп</button></a>");

client. println ("</body>");
client. println ("</html>"); 
break; 
}
}
}
delay (1); 
client. stop();
}
}
