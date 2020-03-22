#include "LibFunction.h"  


//-----------------------------------------------------
//uInt16ToText
//-----------------------------------------------------
void uInt16ToText(unsigned short Value, char *Buf)
{//0 .. 65535
	unsigned short pValue=Value;
	unsigned short tempValue=Value;	
	char i=0,n=0;

	if(pValue>=10000){
		tempValue=pValue/10000;
		pValue=pValue-(tempValue*10000);  		
	  Buf[i]=tempValue+0x30;	
    n=1;		
	}else Buf[i]=0x20; 	
	i++;	
	
	if(pValue>=1000){
		tempValue=pValue/1000;
		pValue=pValue-(tempValue*1000);  		
	  Buf[i]=tempValue+0x30;		
		n=1;
	}else if(n==0)Buf[i]=0x20; else Buf[i]=0x30; 	
	i++;	
	
	
	if(pValue>=100){
		tempValue=pValue/100;
		pValue=pValue-(tempValue*100);  		
	  Buf[i]=tempValue+0x30;	
    n=1;		
	}else if(n==0)Buf[i]=0x20; else Buf[i]=0x30; 	
	i++;	
	
	if(pValue>=10){
		tempValue=pValue/10;
		pValue=pValue-(tempValue*10);  		
	  Buf[i]=tempValue+0x30;		
		n=1;
	}else if(n==0)Buf[i]=0x20; else Buf[i]=0x30;  	
	i++;		
	
	Buf[i]=pValue+0x30;
	i++;	
	Buf[i]=0;	
}
	

//----------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------//
 
void strcpy(char *Buf2,char *Buf1) // загрузить из массива Buf2 в массив Buf1  отлажено
{ int i=0;
  do{
    Buf1[i] = Buf2[0];
    i++;
  }
  while( *Buf2++ ) ;
}

//----------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------//
 

void IntToText(long Value,  char *Buf)
     {
      //// Convert value 
      char BCD[4];
      char j=0, i = 0,Count =5 ,c;
      
    //  bin2bcd32(BCD, Value);
     //   Buf[0]=BCD[0];
      
      while( Count--  )
           {  
            c=BCD[j++];       
            if (i||c>>4) Buf[i++]= (c >> 4  )  + 0x30;
            if (i||c)   Buf[i++]= (c &  0x0f) + 0x30;
           }     
      Buf[i]=0;  
      
     }
//----------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------//
 
