#include "main.h"  

int main(void)
{
  LEDsini();	
	_InitDrive();	
	while(1)
	{		
	  RED_ON();          	
		delay_ms(500);
	  RED_OFF();           	
    delay_ms(500);		
	}
}
 
