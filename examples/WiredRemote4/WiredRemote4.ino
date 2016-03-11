
#include <HBridge84.h>

#define XINPUT 4
#define YINPUT 5

HBridge84 left(9,10,7), right(3,2,8);

void setup() {

}

void loop() {
  int a,b,x,y;

  // second reading is more accurate
  x = analogRead(XINPUT); 
  x = analogRead(XINPUT); 
  y = analogRead(YINPUT);
  y = analogRead(YINPUT);
  
  if (y > 512) { // right ?
    y = (y - 512) / 2;
    a = x - y;
    b = x + y;
  } else if (y < 511) { // left ?
    y = (511 - y) / 2;    
    a = x + y;
    b = x - y;
  } else {// y == 511
    a = x;
    b = x;
  }
  if (a > 1023) a = 1023;
  if (b > 1023) b = 1023;
  if (a < 0) a = 0;
  if (b < 0) b = 0;
  
  left.drive(a);
  right.drive(b);
  
  delay(1);
}
