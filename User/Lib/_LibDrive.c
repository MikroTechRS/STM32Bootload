#include "_LibDrive.h"  

uint16_t delay_count=0;



//Heap_Size1       EQU     0x00000200



#define TimersMax 31
//#define PERIPH_BASE2           ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region                                */
// /*!< Backup SRAM(4 KB) base address in the alias region   
//#define BKPSRAM_test_2          ((uint32_t)0x40024000)

//#define RCC_test                 ((RCC_TypeDef *) RCC_BASE)

/*
#define PERIPH_BASE_test           ((uint32_t)0x40000000) //!< Peripheral base address in the alias region 
#define AHB1PERIPH_BASE_test       (PERIPH_BASE_test + 0x00020000)
#define RCC_BASE_test              (AHB1PERIPH_BASE_test + 0x3800)
#define RCC_test                   ((uint32_t *) RCC_BASE_test )
*/
uint16_t Timers[TimersMax];


//__heap_base EQU 0xD0000000       ; equal to the start of the heap


/*

int val2;
__asm
    {
    MOV val2,0xFFFF0000
    MOV val,val,LSL #16
    }
  return val+val2;
}	
*(unsigned long*)(0x40023830) |= 0x8;
*/



//-----------------------------------------------------
//1ms interupt
//-----------------------------------------------------
void SysTick_Handler(void)  //1ms interupt
{
  if (delay_count>0){delay_count--;}
//	for(int i=0;i<TimersMax+1;i++){
//	  if (Timers[i]>0){Timers[i]--;};
//};	
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
	// for(int i=0;i<TimersMax+1;i++){Timers[i]=0;};
	 delay_count=0;
	 SysTick_Config(SystemCoreClock/1000);//1ms	Timer	
}

