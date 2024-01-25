#define PIN_TRIG 9
#define PIN_ECHO 8
long duration, cm;
void setup() {
// Инициализируем взаимодействие по последовательному порту
Serial.begin (115200);
// Определяем вводы и выводы
pinMode(PIN_TRIG, OUTPUT);
pinMode(PIN_ECHO, INPUT);
}
void loop() {
digitalWrite(PIN_TRIG, LOW);
delayMicroseconds(5);
digitalWrite(PIN_TRIG, HIGH);
delayMicroseconds(10);
digitalWrite(PIN_TRIG, LOW);
duration = pulseIn(PIN_ECHO, HIGH);
cm = (duration / 2) / 29.1;
Serial.print("Расстояние до объекта: ");
Serial.print(cm);
Serial.println(" см.");
delay(250);
}
