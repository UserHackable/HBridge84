
#include <HBridge84.h>

#define XINPUT 5
#define YINPUT 4

HBridge84 left(9,10,7), right(3,2,8);

void setup() {
  pinMode(LEFTA, OUTPUT);
  pinMode(LEFTB, OUTPUT);
  pinMode(LEFTEN, OUTPUT);
}

void loop() {
  left.forward(255); delay(500); left.coast();
  right.forward(255); delay(500); right.coast();
  left.reverse(255); delay(500); left.coast();
  right.reverse(255); delay(500); right.coast();

}
