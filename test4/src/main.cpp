#include <wiringPi.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>

using namespace std;

int main (void)
{
	int stanDiody=0;
	wiringPiSetupGpio();
	pinMode(4, INPUT);
	pullUpDnControl(4, PUD_UP);
	pinMode(22, INPUT);
	pullUpDnControl(22, PUD_UP);
	pinMode (17, OUTPUT);
	pinMode (18,PWM_OUTPUT);
	pwmWrite (18,200);

	while(1)
	{
		digitalWrite(17,stanDiody);
		if(digitalRead(22) == LOW)
		{
			stanDiody=1;
			cout<<"dioda ON"<<endl;
		}
		if(digitalRead(4)==LOW)
		{
			stanDiody=0;
			cout<<"dioda OFF"<<endl;
		}
	}
	return 0 ;
}


