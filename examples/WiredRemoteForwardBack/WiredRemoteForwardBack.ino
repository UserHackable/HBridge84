
#include "HBridge84.h"

#define XINPUT 4
#define YINPUT 5

HBridge84 left(9,10,7), right(3,2,8);

void setup() {

}

void loop() {
  int x;

  // second reading is more accurate
  x = analogRead(XINPUT); 
  x = analogRead(XINPUT); 

  
  left.drive(x);
  right.drive(x);
  
  delay(1);
}
