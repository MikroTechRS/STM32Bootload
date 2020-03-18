#ifndef MAIN_H
#define MAIN_H

#include "mcu_ini.h"   
#include "_LibDrive.h"  
//#include "stm32f4xx.h"                  // Device header

#define RED_ON()  GPIO_SetBits(GPIOD,GPIO_Pin_13)
#define RED_OFF() GPIO_ResetBits(GPIOD,GPIO_Pin_13)
#define DELAY     500

#endif

