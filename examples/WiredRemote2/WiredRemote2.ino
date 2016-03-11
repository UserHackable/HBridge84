
#define XINPUT 5
#define YINPUT 4
#define LEFTA 9
#define LEFTB 10
#define LEFTEN 7


void setup() {
  pinMode(LEFTA, OUTPUT);
  pinMode(LEFTB, OUTPUT);
  pinMode(LEFTEN, OUTPUT);
}

int a;
void loop() {
  digitalWrite(LEFTA, HIGH);
  for(a = 80; a < 255; ++a) {
    analogWrite(LEFTEN, a);
    delay(10);
  }
  for(; a > 80; --a) {
    analogWrite(LEFTEN, a);
    delay(10);
  }
  digitalWrite(LEFTEN, LOW);
  digitalWrite(LEFTA, LOW);
  delay(1000);
  digitalWrite(LEFTB, HIGH);
  digitalWrite(LEFTEN, HIGH);
  delay(1000);
  digitalWrite(LEFTEN, LOW);
  digitalWrite(LEFTB, LOW);
  delay(1000);
}
