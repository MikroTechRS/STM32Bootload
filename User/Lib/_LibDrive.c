#include "_LibDrive.h"  
#include "GlobalData.h"  


uint16_t delay_count=0;
int32_t* aTimer;
int32_t  Timer;

//-----------------------------------------------------
//1ms interupt
//-----------------------------------------------------
void SysTick_Handler(void)        //1ms interupt
{
  if (delay_count>0)delay_count--; //delay_ms

  aTimer=&Timer1;
	for(int i=1;i<TimersMax+1;i++)
	{
		Timer=*aTimer;		
	  if (Timer>0)
    {
		  Timer--;
			*aTimer =Timer;			
	  };
		aTimer++;
  };			
	Timer1++;
}

//-----------------------------------------------------
//
//-----------------------------------------------------
void delay_ms(uint16_t delay_temp)  //1ms
{
	delay_count=delay_temp;	
  while(delay_count){};
}
	  
 
//-----------------------------------------------------
//
//-----------------------------------------------------

void _InitDrive(void)  //1ms
{	 
   aTimer=&Timer1;		 
	 for(int i=0;i<TimersMax+1;i++){
	   *aTimer = 0;
		 aTimer++;
	 }; 	 
	 delay_count=0;
	 SysTick_Config(SystemCoreClock/1000);//1ms	Timer	
}

