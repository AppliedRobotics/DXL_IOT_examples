#define M1_dir 2
#define M1_Speed 3
volatile int val = 50;
void setup() {
  pinMode(M1_dir, OUTPUT);
  pinMode(M1_Speed, OUTPUT);
  digitalWrite(M1_dir, LOW);
  analogWrite(M1_Speed, val);
  delay(2000);
  digitalWrite(M1_dir, HIGH);
  analogWrite(M1_Speed, val);
  delay(2000);
  val = 0;
  analogWrite(M1_Speed, val);
}
void loop() {
}
