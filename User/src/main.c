#include "stm32f4xx.h"                  // Device header


int main(void)
{
	uint32_t i;
	
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOCEN;  // Clok register
	
	GPIOC->MODER=0x55000000;     //
	GPIOC->OTYPER=0;             // rezistor
	GPIOC->OSPEEDR=0;            // speed

	
	while(1)
	{
	  GPIOC->ODR=0xF000;           	
		for(i=0;i<10000000;i++){}
	  GPIOC->ODR=0x0000;           	
		for(i=0;i<10000000;i++){}		
	}
}
 
	
	
	
	
	
	

/*
#include "main.h"   

#define APP_START_ADDRESS 0x0800C000 //????? ?????? ?????????

//-----------------------------------------------------
//
//-----------------------------------------------------
int main(void)
{*/
	/*
//----start program---------
	__disable_irq();  //stop itnerupt __set_PRIMASK(1); //????????? ??????????
	SCB->VTOR=APP_START_ADDRESS; // SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; Vector Table Relocation in Internal FLASH 
  __enable_irq();  //start itnerupt  __set_PRIMASK(0);//????????? ??????????
//--------------------------		
	*/
	
	
 // LEDsini();
//	_InitDrive(); 
	
/*	
//----------bootloader--------------------
	uint32_t appJumpAdress;
	appJumpAdress=*((volatile uint32_t*)(APP_START_ADDRESS+4));
	
	void(*GoToApp)(void);	
	GoToApp=(void(*)(void))appJumpAdress;
*/	
/*?????????? ??? ????????? ?? APB1 */
// RCC->APB1RSTR = 0xFFFFFFFF; RCC->APB1RSTR = 0x0; 
/*?????????? ??? ????????? ?? APB2 */ 
// RCC->APB2RSTR = 0xFFFFFFFF; RCC->APB2RSTR = 0x0; 
// RCC->APB1ENR = 0x0; /* ????????? ??? ????????? ?? APB1 */ 
// RCC->APB2ENR = 0x0; /* ????????? ??? ????????? ?? APB2 */
// RCC->AHBENR = 0x0; /* ????????? ??? ????????? ?? AHB */
 /* ?????????? ??? ????????? ?????????? ?? ?????????, ????????? ?? HSI*/
 //RCC_DeInit();  	
	/*
	
	__disable_irq();  //stop itnerupt
	__set_MSP(*((volatile uint32_t*)APP_START_ADDRESS));//stek
	GoToApp();
//----------------------------------------	
*/	
	/*
	__ASM("NOP");
//	__ASM("mov eax, a");	
	
	
	
	
	while(1)
	{        	
		RED_ON();
		delay_ms(DELAY);
    RED_OFF();	
		delay_ms(DELAY);	   			
	}	
	
	// GPIOD->ODR=0xF000;  
}


//-----------------------------------------------------
//  END
//-----------------------------------------------------

*/

/*

int main(void)
{
	uint32_t i;
	
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;  // Clok register
	
	GPIOD->MODER=0x55000000;     //
	GPIOD->OTYPER=0;             // rezistor
	GPIOD->OSPEEDR=0;            // speed

	
	while(1)
	{
	  GPIOD->ODR=0xF000;           	
		for(i=0;i<2000000;i++){}
	  GPIOD->ODR=0x0000;           	
		for(i=0;i<2000000;i++){}		
	}
}
 



	
	while(1)
	{        	
		GPIO_SetBits(GPIOD,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15 );
		for(i=0;i<2000000;i++){}   
    GPIO_ResetBits(GPIOD,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);	
		for(i=0;i<2000000;i++){}	   			
	}
	
		GPIO_SetBits(GPIOD,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15 );
		delay_ms(500);
    GPIO_ResetBits(GPIOD,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);	
		delay_ms(500);
*/



