#ifndef ILI9488_H
#define ILI9488_H

#include "stm32f4xx.h"                  // Device header

void ILI9488_ini();  
void Rectangle(uint16_t _Color,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void Write_Text(char* Text,uint16_t X_Coord,uint16_t Y_Coord);

extern uint16_t TFT_Color;
extern uint16_t TFT_Fon;

#endif




