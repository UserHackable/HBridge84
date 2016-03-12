
#include <HBridge84.h>

HBridge84 left(9,10,7), right(3,2,8);

void setup() {
}

void loop() {
  left.forward(); delay(500); left.coast(); delay(500);
  right.forward(); delay(500); right.coast(); delay(500);
  left.reverse(); delay(500); left.coast(); delay(500);
  right.reverse(); delay(500); right.coast(); delay(500);
}
