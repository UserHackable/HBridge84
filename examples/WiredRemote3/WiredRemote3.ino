
#include <HBridge84.h>

#define XINPUT 4
#define YINPUT 5

HBridge84 left(9,10,7), right(2,3,8);

void setup() {

}

void loop() {
  int x,y;
  x = analogRead(XINPUT); 
  y = analogRead(YINPUT);
  
  left.drive(x);
  right.drive(y);
  
  delay(1);
}
