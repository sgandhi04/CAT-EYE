//include librarys
#include <Pixy2.h>
//create pixy object
Pixy2 pixy;
//define led pins
int led1 = 9;
int led2 = 8;
//setup code
void setup()
{
  //setup leds
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  //initilize pixy2
  pixy.init();
}
//loop code
void loop()
{ 
  //grab data from pixy
  pixy.ccc.getBlocks();
  //if mask is detected...
  if (pixy.ccc.numBlocks)
  {
    //turn off red led
    digitalWrite(led1, LOW);
    //turn on green led
    digitalWrite(led2, HIGH);
    //turn off buzzer
    noTone(7); 
    delay(1000);
  }
  //else...
  else {
    //turn on red led
    digitalWrite(led1, HIGH);
    //turn off green led
    digitalWrite(led2, LOW);
    //turn on buzzer
    tone(7, 261);
    delay(1000);
  }
}
