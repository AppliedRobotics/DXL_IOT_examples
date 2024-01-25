#define K1 10
#define K2 11
#define K3 12
#define K4 13
void setup() {
pinMode(K1, OUTPUT);
pinMode(K2, OUTPUT);
pinMode(K3, OUTPUT);
pinMode(K4, OUTPUT);
digitalWrite(K1, HIGH);
digitalWrite(K2, LOW);
delay(2000);
digitalWrite(K1, LOW);
digitalWrite(K2, HIGH);
delay(2000);
digitalWrite(K2, LOW);
digitalWrite(K3, HIGH);
delay(2000);
digitalWrite(K3, LOW);
digitalWrite(K4, HIGH);
delay(2000);
digitalWrite(K4, LOW);
}
void loop() {
}
