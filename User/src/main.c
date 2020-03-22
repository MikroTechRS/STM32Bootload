#include "main.h"   

char message[] = {"zerÌ„Â„ÂÍ„ÍÌwgfd"};

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
	Rectangle(0xFFFF, 0, 0,479,319);
  Rectangle(0x0000, 1, 1,478,318);                       
  Rectangle(0x03E0,10,10,470,310);	
	
	TFT_Color= 0xFFFF;                               
	TFT_Fon  = 0x0000;

  char Text1[50]= "12345678";
  Write_Text(Text1,250,20);	
  strcpy("34567",Text1);
  Write_Text(Text1,250,40);

	Write_Text(message,20,20);	
	Write_Text("message",20,40);	

  int xVal=0xFFFF;	
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
  	Rectangle(_Color,10,100,470,310);		
		
    uInt16ToText(xVal++, Text1);
	  Write_Text(Text1,250,60);	
		
	  _Color++;
  }			
}	
	
	
	
	
	 

