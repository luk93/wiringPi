#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main (void)
{
	cout << "Zapalanie i gaszenie diody\n";

  wiringPiSetup();
  pinMode(0, OUTPUT); 				//gpio17-wyjscie
  digitalWrite(0, LOW);			//gpio17-stan niski
  pinMode(7, INPUT);				//gpio4-wejscie
  pullUpDnControl(7, PUD_UP);		//gpio4-input_pullup

  for(;;)
  {
	if(digitalRead(7) == HIGH){ 	//przycisk nie wcisniety
		digitalWrite(0, LOW); 		//stan niski na diodzie
		cout << "LOW\n";
		delay(50);}
	else{ 							//przycisk wcisniety
		digitalWrite(0, HIGH); 	//stan wysoki na diodzie
		cout << "HIGH\n";
		delay(50);}
  }
  return 0 ;
}

