#include <SPI.h> // Подключаем библиотеку SPI
#include <Ethernet.h> // Подключаем библиотеку Ethernet
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // Вводим MAC адрес
IPAddress ip(169, 254, 21, 70); // Указываем статический IP
EthernetServer server(80); // Инициализация библиотеки
void setup()
{
Serial.begin(115200); 
while (!Serial) {;}
Ethernet.begin(mac, ip); 
server.begin();
Serial.print("server is at ");
Serial.println(Ethernet.localIP());
}
void loop()
{EthernetClient client = server.available(); 
if (client) {
Serial.println("new client");
boolean currentLineIsBlank = true;
while (client.connected()) {
if (client.available()) {
char c = client.read();
Serial.write(c);
if (c == '\n' && currentLineIsBlank) {
client.println("HTTP/1.1 200 OK");
client.println("Content-Type: text/html");
client.println("Connection: close"); 
client.println("Refresh: 5v"); 
client.println();
client.println("<!DOCTYPE HTML>");
client.println("<html>");
for (int analogChannel = 10; analogChannel < 16; analogChannel++)
{int sensorReading = analogRead(analogChannel);
client.print("analog input ");
client.print(analogChannel);
client.print(" is ");
client.print(sensorReading);
client.println("<br />");}
client.println("</html>");
break;}
if (c == '\n') {
currentLineIsBlank = true;
} else if (c != '\r') {
currentLineIsBlank = false;
}
}
}
delay(1);
client.stop();
Serial.println("client disconnected");
}
}
