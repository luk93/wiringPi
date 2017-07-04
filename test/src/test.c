#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>

int main (void)
{
  printf("Mruganie dioda") ;
  wiringPiSetup();
  pinMode(0, OUTPUT);         //pin 17

  for(;;)
  {

    digitalWrite(0, HIGH) ;       // migaj!
    delay(500) ;   // mS
    digitalWrite(0, LOW) ;       //  przestan!
    delay(500) ;
  }
  return 0 ;
}
