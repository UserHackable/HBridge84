
#include <HBridge84.h>

HBridge84 left(9,10,7), right(3,2,8);

void setup() {
}

void loop() {
  left.forward();
  right.forward();
  delay(500); 
  left.coast();
  right.coast();
  delay(500);  
  left.reverse(); 
  right.forward();
  delay(110);
  left.coast();
  right.coast();  
  delay(500); 
}
