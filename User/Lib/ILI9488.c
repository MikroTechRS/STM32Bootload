#include "ILI9488.h"  
#include "_LibDrive.h" 
#include "_Font_8x16.h" 

#define TFT_D0                 ((uint16_t)0x0001)  /* Pin 0 selected */
#define TFT_D1                 ((uint16_t)0x0002)  /* Pin 1 selected */
#define TFT_D2                 ((uint16_t)0x0004)  /* Pin 2 selected */
#define TFT_D3                 ((uint16_t)0x0008)  /* Pin 3 selected */
#define TFT_D4                 ((uint16_t)0x0010)  /* Pin 4 selected */
#define TFT_D5                 ((uint16_t)0x0020)  /* Pin 5 selected */
#define TFT_D6                 ((uint16_t)0x0040)  /* Pin 6 selected */
#define TFT_D7                 ((uint16_t)0x0080)  /* Pin 7 selected */
#define TFT_RST                ((uint16_t)0x0100)  /* Pin 8 selected */
#define TFT_WR                 ((uint16_t)0x0200)  /* Pin 9 selected */
#define TFT_DC                 ((uint16_t)0x0400)  /* Pin 10 selected */


uint16_t TFT_Color;
uint16_t TFT_Fon;

//-----------------------------------------------------
//ILI9488_Pin_ini
//-----------------------------------------------------
void ILI9488_Pin_ini()  
{
	GPIO_InitTypeDef ILI9488_Pin;		
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);		
	ILI9488_Pin.GPIO_Pin   = TFT_D0|TFT_D1|TFT_D2|TFT_D3|TFT_D4|TFT_D5|TFT_D6|TFT_D7|TFT_RST|TFT_WR|TFT_DC;
	ILI9488_Pin.GPIO_Mode  = GPIO_Mode_OUT;
	//GPIO_Speed_100MHz;//GPIO_Speed_50MHz;//GPIO_Speed_25MHz;//GPIO_Speed_2MHz;	
	ILI9488_Pin.GPIO_Speed =GPIO_Speed_25MHz;
	ILI9488_Pin.GPIO_OType = GPIO_OType_PP;
  ILI9488_Pin.GPIO_PuPd  = GPIO_PuPd_NOPULL;	
	GPIO_Init(GPIOB, &ILI9488_Pin);		
}	


void TFT_Command(unsigned char cmd)
{	
	GPIOB->ODR = cmd|TFT_RST;		
	GPIOB->ODR = cmd|TFT_RST|TFT_WR;		
	GPIOB->ODR = cmd|TFT_RST;			
}

void TFT_Data(unsigned char cmd)
{
	GPIOB->ODR = cmd|TFT_RST|TFT_DC; 	
	GPIOB->ODR = cmd|TFT_RST|TFT_DC|TFT_WR;		
	GPIOB->ODR = cmd|TFT_RST|TFT_DC;
}

void TFT_DataWord(uint16_t _data)
{
	//TFT_Data(_data>>8);
	uint8_t _pdata=_data>>8;
	GPIOB->ODR = _pdata|TFT_RST|TFT_DC; 	
	GPIOB->ODR = _pdata|TFT_RST|TFT_DC|TFT_WR;		
	GPIOB->ODR = _pdata|TFT_RST|TFT_DC;	
	//TFT_Data(_data);
	_pdata=_data;
	GPIOB->ODR = _pdata|TFT_RST|TFT_DC; 	
	GPIOB->ODR = _pdata|TFT_RST|TFT_DC|TFT_WR;		
	GPIOB->ODR = _pdata|TFT_RST|TFT_DC;	
}
//-----------------------------------------------------
//ILI9488_Reset
//-----------------------------------------------------
void ILI9488_Reset()  
{
 GPIOB->ODR =0 ;     
 delay_ms(15);         
 GPIOB->ODR =TFT_RST ;  
 delay_ms(15);         
}		

//-----------------------------------------------------
//ILI9488_ini
//-----------------------------------------------------
void ILI9488_ini()   
{
  ILI9488_Pin_ini();
  ILI9488_Reset(); 
	
  TFT_Command(0x11);
  delay_ms(20);         	
	
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
        TFT_Data(0x08);      

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
				
		//		TFT_Command(0x21);// Display Inversion OFF
				TFT_Command(0x20);	

   TFT_Command(0x36);     //Memory Access Control (36h)
 TFT_Data(0b00101000);   //TFT_Data(%00101000);
//          |||||||+--D0  Switching between Common outputs and RAM  Don�t care
//          ||||||+---D1  Switching between Segment outputs and RAM  Don�t care
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
        delay_ms(120); // Delay_ms(120);
        TFT_Command(0x0029);                // Display ON
        TFT_Command(0x002C);		
}	

//-----------------------------------------------------
//Rectangle
//-----------------------------------------------------
void Rectangle(uint16_t _Color,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
  TFT_Command(0x2A);TFT_DataWord(x1);TFT_DataWord(x2);
  TFT_Command(0x2B);TFT_DataWord(y1);TFT_DataWord(y2);
  TFT_Command(0x2C);
	
	uint32_t i=(x2-x1+1)*(y2-y1);
	while(i)
	{
		TFT_DataWord(_Color);		
		i--;
	}	
}
																					
//-----------------------------------------------------
//Write_Text
//-----------------------------------------------------
void Write_Text1(char* Text,uint16_t X_Coord,uint16_t Y_Coord)
{	
	uint16_t Dtest,uk;	
	while(*Text)
	{
	//if(*Text>0){
		uint16_t* Adres_Char8x16= &Font_8x16[0];		
	  uk =*Text+0x20;
		Adres_Char8x16= &Font_8x16[0];
    Adres_Char8x16 = Adres_Char8x16+(uk << 3);
		
		TFT_Command(0x2A);TFT_DataWord(X_Coord);
      X_Coord=X_Coord+7; TFT_DataWord(X_Coord);
    TFT_Command(0x2B);TFT_DataWord(Y_Coord);
      Y_Coord=Y_Coord+15;TFT_DataWord(Y_Coord);
    TFT_Command(0x2C);
		
		for(int y=0;y<8;y++){
			 Dtest=0x8000;   
        for(int x=0;x<16;x++){   					
          if( Dtest & *Adres_Char8x16)TFT_DataWord(TFT_Color);          
				  	else TFT_DataWord(TFT_Fon);          
		      Dtest=Dtest >> 1;
        }
        Adres_Char8x16++;
		}
	  Y_Coord=Y_Coord-15;	 
	 	X_Coord++;
		
		Text++;	
//	}
	}	
}

//-----------------------------------------------------
//Write_Text                                                        
//-----------------------------------------------------
void Write_Text(char* Text,uint16_t X_Coord,uint16_t Y_Coord)
{	
	uint16_t Dtest,uk,uk_Text=0;		
	while(Text[uk_Text])
	{
		uint16_t* Adres_Char8x16= &Font_8x16[0];		

	  uk =Text[uk_Text++]-0x20;
		Adres_Char8x16= &Font_8x16[0];
    Adres_Char8x16 = Adres_Char8x16+(uk << 3);
		
		TFT_Command(0x2A);TFT_DataWord(X_Coord);
      X_Coord=X_Coord+7; TFT_DataWord(X_Coord);
    TFT_Command(0x2B);TFT_DataWord(Y_Coord);
      Y_Coord=Y_Coord+15;TFT_DataWord(Y_Coord);
    TFT_Command(0x2C);
		
		for(int y=0;y<8;y++){
			 Dtest=0x8000;   
        for(int x=0;x<16;x++){   					
          if(Dtest & *Adres_Char8x16)TFT_DataWord(TFT_Color);          
				  	else TFT_DataWord(TFT_Fon);          
		      Dtest=Dtest >> 1;
        }
        Adres_Char8x16++;
		}
	  Y_Coord=Y_Coord-15;	 
	 	X_Coord++;
	}	
}


