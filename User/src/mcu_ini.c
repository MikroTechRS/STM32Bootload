#include "mcu_ini.h"  

//-----------------------------------------------------
//
//-----------------------------------------------------
void LEDsini(void)  //1ms
{
	GPIO_InitTypeDef GPIO_Init_Led;		
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);		
	GPIO_Init_Led.GPIO_Pin   = GPIO_Pin_13;
	GPIO_Init_Led.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_Init_Led.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init_Led.GPIO_OType = GPIO_OType_PP;
  GPIO_Init_Led.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOC, &GPIO_Init_Led);		
	
}
    