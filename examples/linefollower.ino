
#include <HBridge84.h>

HBridge84 right(9,10,7), left(3,2,8);

int sensorPin = 0;
int sensorRead;

void setup()
{
  pinMode(sensorPin, INPUT);
}

int speed = 110;

void loop()
{
  //read value from the receiver
  sensorRead = analogRead(sensorPin);

  //on black line
  if(sensorRead > 100)
  {
    //ccw
    left.reverse(speed);
  }
  //on white table
  else
  {
    //cw
    right.reverse(speed);
  }
  delay(20);
  left.coast();
  right.coast();

}
