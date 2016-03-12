
#include <HBridge84.h>

HBridge84 left(9,10,7), right(3,2,8);

void setup() {
}

int a;
void loop() {
  for(a = 0; a < 255; ++a) {
    left.forward(a);
    delay(10);
  }
  for(; a > 0; --a) {
    left.forward(a);
    delay(10);
  }
  left.coast();

  for(a = 0; a < 255; ++a) {
    right.forward(a);
    delay(10);
  }
  for(; a > 0; --a) {
    right.forward(a);
    delay(10);
  }
  right.coast();

  for(a = 0; a < 255; ++a) {
    left.reverse(a);
    delay(10);
  }
  for(; a > 0; --a) {
    left.reverse(a);
    delay(10);
  }
  left.coast();

  for(a = 0; a < 255; ++a) {
    right.reverse(a);
    delay(10);
  }
  for(; a > 0; --a) {
    right.reverse(a);
    delay(10);
  }
  right.coast();

}
