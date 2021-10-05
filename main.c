//preprossing
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include "tm4c123gh6pm.h"
#include "functions_prototype.h"


void SystemInit(){};	
	
//main function
	
int main(void)
{
	//decleration
	uint32_t x;
	char* read;
	char*	read2;
  double lat1,lon1,lat2,lon2;
	double dis;
	//function call for intialization
	
	portF_init();
	LCD_init();	
	UART2Init();
	
	//lcd test

	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	delay_milli(500);
	LCD_GotoXY(3, 1);
	LCD_WriteString("Group 25");


		   
	 //read= UART2_ReadStr();
	lat1 = GPGGA_lat (read);
	lon1 = GPGGA_long (read);
	delay_milli(1000);
			 
	while(1)
		{
		x = portF_input();
   	//read2 = UART2_ReadStr();
		delay_milli(1000);
	  lat2 = GPGGA_lat(read2);
	  lon2 = GPGGA_long(read2);
			
		
		
	delay_milli(2000);
			
		dis = distance_m (lat1,lon1,lat2,lon2);
			//
			
		if (x == 0x10 || x == 0x01 || dis>=95 )
				 {
					  portF_output(0x02);
				  	delay_milli(1000);		
					 
				
				  }					
	  else if (x == 0x11)
					{
				    portF_output(0x08);	
					  delay_milli(1000);	
					
					}
	   else 
			  	{
			      portF_output(0x00);	
				  }
				
				  lat1=lat2;
					lon1=lon2;
					LCD_GotoXY(3, 0);
					LCD_WriteDouble(dis);	
					delay_milli(1000);
	
	}
	
	
}
