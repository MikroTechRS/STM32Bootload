#include "GlobalData.h"  

uint16_t delay_count=0;
//-----------------------------------------------------
//1ms interupt
//-----------------------------------------------------
void SysTick_Handler()        //1ms interupt
{
  if (delay_count>0)delay_count--; //delay_ms

	for(int i=1;i<TimersMax;i++)
	{	
    if (Timers[i]>0)Timers[i]--;
  };			
	Timers[0]++;
}

//-----------------------------------------------------
//delay_ms(
//-----------------------------------------------------
void delay_ms(uint16_t delay_temp)  //1ms
{
	delay_count=delay_temp;	
  while(delay_count){};
}	  
 
//-----------------------------------------------------
//
//-----------------------------------------------------
void _InitDrive()  //1ms
{	 		 
	 for(int i=0;i<TimersMax+1;i++)Timers[i]=0; 	 
	 delay_count=0;
	 SysTick_Config(SystemCoreClock/1000);//1ms	Timer	
}

