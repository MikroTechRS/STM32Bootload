#ifndef MAIN_H
#define MAIN_H

#include "mcu_ini.h"   
#include "_LibDrive.h"  
#include "GlobalData.h" 
#include "ILI9488.h" 


#define RED_ON()  GPIO_SetBits(GPIOC,GPIO_Pin_13)
#define RED_OFF() GPIO_ResetBits(GPIOC,GPIO_Pin_13)
#define DELAY     500

#endif






/*
char         	       8	  -128 … 127
unsigned char	       8	  0 … 255
short               16	  -32 768 … 32767
unsigned short      16	  0 … 65535
int                 32	  -2 147 483 648 … 2 147 483 647
unsigned int        32	  0 … 4 294 967 295
long	              32	  -2 147 483 648 … 2 147 483 647
unsigned long	      32	  0 … 4 294 967 295
long long           64	  -9 223 372 036 854 775 808 …9 223 372 036 854 775 807
unsigned long long	64  	0 … 18 446 744 073 709 551 615

float             	32	  -2 147 483 648.0 … 2 147 483 647.0
double	            64	  -9 223 372 036 854 775 808 .0 …9 223 372 036 854 775 807.0
long double         64	  -9 223 372 036 854 775 808 .0 …9 223 372 036 854 775 807.0
*/

















/*

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
 
	
	
	
*/	
	
	

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

/*
define symbol _ICFEDIT_region_RAM_start_          = 0x20000000;
define symbol _ICFEDIT_region_RAM_end_            = 0x20017FFF;
#pragma location= 0x20017BFF
__no_init  uint8_t my_arr[1024];


MEMORY
{
RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 112K
AUX (xrw) : ORIGIN = 0x2001C000, LENGTH = 16K
VECTOR (rx) : ORIGIN = 0x8000000, LENGTH = 16K
EEPROM (rx) : ORIGIN = 0x8004000, LENGTH = 16K
FLASH (rx) : ORIGIN = 0x8008000, LENGTH = 1M-32K
CCM (xrw) : ORIGIN = 0x10000000, LENGTH = 64K 
}

auto, register, static extern




#define APP_START_ADDRESS 0x0800C000  
void GoToUserApp(void)
{
	uint32_t appJumpAddress;
	appJumpAddress = *((volatile uint32_t*)(APP_START_ADDRESS + 4));
	
	void (*GoToApp)(void);	
	
	GoToApp = (void (*)(void))appJumpAddress;
	SCB->VTOR = APP_START_ADDRESS;
	__set_MSP(*((volatile uint32_t*) APP_START_ADDRESS)); //stack pointer (to RAM) for USER app in this address
	GoToApp();
}




 void GoToApp(void) 
{
  while(1)
	{	         	
  delay_ms(500);
  RED_OFF();           	
  delay_ms(500);		
  RED_ON();     
	}
}




#define APP_START_ADDRESS 0x0800C000  
void GoToUserApp(void)
{
	u32 appJumpAddress;
	void (*GoToApp)(void);
	appJumpAddress = *((volatile u32*)(APP_START_ADDRESS + 4));
	appJumpAddress = APP_START_ADDRESS ;
	GoToApp = (void (*)(void))appJumpAddress;
	SCB->VTOR = APP_START_ADDRESS;
	__set_MSP(*((volatile u32*) APP_START_ADDRESS)); //stack pointer (to RAM) for USER app in this address
	GoToApp();
}




















































unit _Drive;
 uses _Data, _Pin;     //   ,_RAM
const
  X_Scrren=480;
  Y_Scrren=320;       //  318;//
procedure Rectangle(_Color:word;x1,y1,x2,y2:word); // ?????? ????????? ?????????????.
Function Write_Text(Text:^char;X_Coord, Y_Coord : word):byte;
procedure UDP_Flash_Boot(D:Byte);
var  Color_Pixel:word;
//procedure Pixel(X,Y:word);              //?????? ?????

var 
  UDP_buf:     array[0..1000] of byte;   external;
  UDP_buf_Out: array[0..15] of byte;     external;
  Key          :   Byte;                 external;
  BX           :   word;                 external;
  
var
  Color       :   word;
  Fon         :   word;
  var
  Flash_address: Dword;
procedure _init;
procedure _init_Pin;
procedure _init_TFT;


Procedure IrBuser(d:boolean);
//Procedure IrPort();
Procedure IrLed1(d:boolean);
Procedure IrLed2(d:boolean);
Procedure IrLed3(d:boolean);
Procedure IrLed4(d:boolean);



implementation


Procedure IrPort();
begin
  PMCON.15:=0;
  LATE    :=Ir_Port;
  Ir_Port_strob  :=1;
   Delay_ms(1);
  Ir_Port_strob  :=0;
  PMCON.15:=1;
end;

Procedure IrBuser(d:boolean);
begin
  Ir_Port.Ir_Buser:=d;
  IrPort();
end;
Procedure IrLed1(d:boolean);
begin
  Ir_Port.Ir_Led1:=d;
  IrPort();
end;
Procedure IrLed2(d:boolean);
begin
  Ir_Port.Ir_Led2:=d;
  IrPort();
end;
Procedure IrLed3(d:boolean);
begin
  Ir_Port.Ir_Led3:=d;
  IrPort();
end;
Procedure IrLed4(d:boolean);
begin
  Ir_Port.Ir_Led4:=d;
  IrPort();
end;

procedure TFT_Command(cmd : byte);begin  TFT_DC:=0; PMDIN1:=cmd;end;
procedure TFT_Data(_data :byte);begin  TFT_DC:=1; PMDIN1:=_data;end;
procedure TFT_DataWord(_data :word);begin  TFT_DC:=1;PMDIN1:=Hi(_data);PMDIN1:=Lo(_data);end;

procedure _init_Pin;
begin
  AD1PCFG :=  0xFFFF;          // ??? ?????? - ????????
  CVRCON.CVREN :=  0;          // ?????????? ????????? ???????? ?????????? ??? ????????????
  TRISF :=0xFFFC;              // ??????? ????? A ?? ?????
  TRISE :=0xFF00;              // ??????? ????? A ?? ?????
  TRISD :=0xFFFF;              // ??????? ????? D ?? ?????
  TRISC :=0xFFFF;              // ??????? ????? C ?? ?????
  TRISB :=0xFFFF;              // ??????? ????? B ?? ?????

  Ir_Port:=0;
  Ir_Port_strob :=0;
  Ir_Port_TRIS:=0;
  IrLed1(1);
  IrLed2(1);


  TFTLed:=0;
  TFTLed_Direction:=0;
  TFTReset:=0;
  TFTReset_Direction:=0;
  
  asm
    MOV #lo_addr(OSCCON), W1 // ???????? ????? ???????? OSCCON ? ??????????? w1
    MOV #0x46, w2            // ????????? ???????? 0x46 ? ??????????? w2
    MOV #0x57, w3            // ????????? ???????? 0x57 ? ??????????? w3
    MOV.b w2, [w1]           // ????????? ???????? 0x46 ?? w2 ? ??????? OSCCON
    MOV.b w3, [w1]           // ????????? ???????? 0x57 ?? w3 ? ??????? OSCCON
    BCLR OSCCON,#6           // ?????????? ??? IOLOCK ? ???????? OSCCON
  end;


  RPOR9  := $0700;    //  RP19 <- SDO1 7     RP18 <-             OUT
  RPOR13 := $0800;    //  RP27 <- SCK1 8     RP26 <-             OUT
  RPINR20:= $FF1A;    //  SCK1 <- $FF        SDI1 <- RP26  $1A   IN
//  RPOR10 := $1200;   //   RP21 <- PWM1 (18)  RP12 <-             OUT

  asm
    MOV #lo_addr(OSCCON), w1
    MOV #0x46,w2
    MOV #0x57,w3
    MOV.b w2,[w1]
    MOV.b w3,[w1]
    BSET OSCCON, #6
  end;
// ?????????  ????????????? ?????
  PMCON :=%1000001000000000; // ???????? ??????????   PMCON:=%1000001100000011;
  PMMODE:=%0000001100000000; // Parallel Port Mode ??????????????????      PMMODE:=%0000001111001111;

end;


var TFTMode:byte;
procedure _init_TFT;
begin
//----- Test --- TFT --------------
  PMCON.15:=0;
  TRISE :=0xFFFF;
  Delay_ms(1);
  TFTMode:= porte and $07;
  TrisE          :=0;
  PMCON.15:=1;



  TFTReset:=1;
  Delay_ms(5);
  TFTReset:=0;
  Delay_ms(15);
  TFTReset:=1;
  Delay_ms(15);


  TFT_Command($11);
  Delay_ms(20);

        TFT_Command(0xF2);                // ?????
        TFT_Data(0x1C);
        TFT_Data(0xA3);
        TFT_Data(0x32);
        TFT_Data(0x02);
        TFT_Data(0xb2);
        TFT_Data(0x12);
        TFT_Data(0xFF);
        TFT_Data(0x12);
        TFT_Data(0x00);

        TFT_Command(0xF1);                // ?????
        TFT_Data(0x36);
        TFT_Data(0xA4);

        TFT_Command(0xF8);                // ?????
        TFT_Data(0x21);
        TFT_Data(0x04);

        TFT_Command(0xF9);                // ?????
        TFT_Data(0x00);
        TFT_Data(0x08);      { }

        TFT_Command(0xC0);                // Power Control 1
        TFT_Data(0x0d);
        TFT_Data(0x0d);

        TFT_Command(0xC1);                // Power Control 2
        TFT_Data(0x43);
        TFT_Data(0x00);

        TFT_Command(0xC2);                // Power Control 3
        TFT_Data(0x00);

        TFT_Command(0xC5);                // VCOM Control
        TFT_Data(0x00);
        TFT_Data(0x48);

{        LCD_Write_COM(0xB6);                // Display Function Control
        LCD_Write_DATA(0x00);
        LCD_Write_DATA(0x22);                // 0x42 = Rotate display 180 deg.
        LCD_Write_DATA(0x3B);
                                  }
        TFT_Command(0xE0);                // PGAMCTRL (Positive Gamma Control)
        TFT_Data(0x0f);
        TFT_Data(0x24);
        TFT_Data(0x1c);
        TFT_Data(0x0a);
        TFT_Data(0x0f);
        TFT_Data(0x08);
        TFT_Data(0x43);
        TFT_Data(0x88);
        TFT_Data(0x32);
        TFT_Data(0x0f);
        TFT_Data(0x10);
        TFT_Data(0x06);
        TFT_Data(0x0f);
        TFT_Data(0x07);
        TFT_Data(0x00);

        TFT_Command(0xE1);                // NGAMCTRL (Negative Gamma Control)
        TFT_Data(0x0F);
        TFT_Data(0x38);
        TFT_Data(0x30);
        TFT_Data(0x09);
        TFT_Data(0x0f);
        TFT_Data(0x0f);
        TFT_Data(0x4e);
        TFT_Data(0x77);
        TFT_Data(0x3c);
        TFT_Data(0x07);
        TFT_Data(0x10);
        TFT_Data(0x05);
        TFT_Data(0x23);
        TFT_Data(0x1b);
        TFT_Data(0x00);

     Case TFTMode of
       1: TFT_Command(0x21) // Display Inversion OFF
       else TFT_Command(0x20);
     end;

   TFT_Command($36);     //Memory Access Control (36h)

  TFT_Data(%00101000);   //TFT_Data(%00101000);
//          |||||||+--D0  Switching between Common outputs and RAM  Don’t care
//          ||||||+---D1  Switching between Segment outputs and RAM  Don’t care
//          |||||+----D2  Display Data Latch Order  // ???
//          ||||+-----D3  RGB/BGR Order
//          |||+------D4  Line Address Order    // ???
//          ||+-------D5  Page/Column Order     //??????? ?? 90 ??????? Y
//          |+--------D6  Column Address Order  //??????? X
//          +---------D7  Page Address Order    //??????? X,Y

        TFT_Command(0x3A);                // Interface Pixel Format
        TFT_Data(0x55);

        TFT_Command(0x2A);                // Column Addess Set
        TFT_Data(0x00);
        TFT_Data(0x00);
        TFT_Data(0x01);
        TFT_Data(0xDF);

        TFT_Command(0x002B);                // Page Address Set
        TFT_Data(0x00);
        TFT_Data(0x00);
        TFT_Data(0x01);
        TFT_Data(0x3f);
        Delay_ms(120);
        TFT_Command(0x0029);                // Display ON
        TFT_Command(0x002C);
end;



procedure _init;
begin
  _init_Pin;
  _init_TFT;
end;




procedure Rectangle(_Color:word;x1,y1,x2,y2:word); // ?????? ????????? ?????????????.
var
  i:dword;
begin
  TFT_Command($2A);TFT_DataWord(x1);TFT_DataWord(x2);
  TFT_Command($2B);TFT_DataWord(y1);TFT_DataWord(y2);
  TFT_Command($2C);TFT_DC:=1;
  i:=(x2-x1+1)*(y2-y1);
  while i <> 0 do
  begin
    PMDIN1:= hi(_Color);
    PMDIN1:= lo(_Color);
    dec(i);
  end;
end;


//------------------------------------------------------------------------------
//-------------------------------- ????? ---------------------------------------
//------------------------------------------------------------------------------
Function Write_Text(Text:^char;X_Coord, Y_Coord : word):byte;
var
   Dtest,uk:word;
   Adres_Char8x16: ^word;
   x,y,j:byte;
begin
  result := 0;
  while Text^<>0 do
  begin
    inc(result);
    Adres_Char8x16:= @Font_8x16;
    uk:=Text^-$20;
    if Text^>$0BF  then uk:=uk-$40;
    Adres_Char8x16:= Adres_Char8x16+uk shl 3;
      TFT_Command($2A);TFT_DataWord(X_Coord);
           X_Coord:=X_Coord+7; TFT_DataWord(X_Coord);
      TFT_Command($2B);TFT_DataWord(Y_Coord);
           Y_Coord:=Y_Coord+15;TFT_DataWord(Y_Coord);
      TFT_Command($2C);
      TFT_DC:=1;
      for y:=0 to 7 do
      begin
        Dtest:=$8000;
        for x:=15 Downto 0 do
        begin
          if Dtest and Adres_Char8x16^  then begin
            PMDIN1:=hi(Color); PMDIN1:=lo(Color);
          end else begin
            PMDIN1:=hi(Fon); PMDIN1:=lo(Fon);
          end;
          Dtest:=Dtest shr 1;
        end;
        inc(Adres_Char8x16);
      end;
      Y_Coord:=Y_Coord-15;
    inc(Text);
    inc(X_Coord);
  end;
end;






*/



