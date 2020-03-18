#include "main.h"  

int main(void)
{
  LEDsini();	
	_InitDrive();	
  RED_ON();          	
  delay_ms(500);
  RED_OFF();           	
  delay_ms(500);	
	
	int pLed=0;
	while(1)
	{	
    if (Timer2==0){
			if(pLed==0){
				RED_ON();
			  pLed=1;
				Timer2=1000;
			}
      else{
				RED_OFF();			
			  pLed=0;
				Timer2=50;
			}			
		}					
	}	
}

