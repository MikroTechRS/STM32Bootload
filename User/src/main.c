#include "main.h"  

 void LedBlink(void) 
{
  RED_ON();          	
  delay_ms(500);
  RED_OFF();           	
  delay_ms(500);		
  RED_ON();          	
  delay_ms(500);
  RED_OFF();           	
  delay_ms(500);
	RED_ON();
}

int main(void)
{	
  LEDsini();	
	_InitDrive();	
  
	
	ILI9488_ini();
	
	Rectangle(0xFFFF,10,10,470,310);
  Rectangle(0xFF00,10,10,470,310);
  Rectangle(0x0FF0,10,10,470,310);
  Rectangle(0x00FF,10,10,470,310);
  Rectangle(0xFF00,10,10,470,310);
  Rectangle(0x0FF0,10,10,470,310);
  Rectangle(0x00FF,10,10,470,310);
	
	LedBlink();
	
	int pLed=0;
	uint32_t _Color=0x00FF;
	while(1)
	{	
    if (Timer2==0){
	    if(pLed==0){
	  		 RED_ON();
	  		 pLed=1;
		  	 Timer2=50;
		  }
      else{
		  	 RED_OFF();			
		  	 pLed=0;
		  	 Timer2=1000;
		  }			
	  }		
	 Rectangle(_Color,10,10,470,310);
		
	if(_Color==0x0000)_Color=0x000F;	
	_Color=_Color<<1;	
		
  }			
}	
	
	
	
	
	 

