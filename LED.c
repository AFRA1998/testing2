#include "LED.h"
#define OFFSET_IDR                 (0X10/4)
#define OFFSET_BSRR                (0x18/4)
#define PERIPHERAL_BASE            0x40000000UL
#define AHB1PERIPHERAL_OFFSET      0x0020000UL
#define AHB1PERIPHERAL_BASE	(PERIPHERAL_BASE+ AHB1PERIPHERAL_OFFSET)
#define GPIOD_OFFSET                0x40020C00UL
#define GPIOD_BASE (PERIPHERAL_BASE + GPIOD_OFFSET)
#define RCC_OFFSET  		    0x380000
#define RCC_BASE (AHB1PERIPHERAL_BASE +  RCC_OFFSET)

#define GPIODEN             (1U<<3)  
#define PIN15	            (1u<<15)
#define LED_BLUE_PIN         PIN15


#define PIN12               (1U<<12)
#define BUUTON_GREEN_INPUT  PIN12


#define AHB1ENR_R_OFFSET         (0x30UL)
#define RCC_AHB1EN_R 	         (*(volatile unsigned int  *)(AHB1ENR_R_OFFSET + RCC_OFFSET))

#define MO_OFFSET_R	        (0x00UL)
#define GPIOD_MODE_R		(*(volatile unsigned int  *)(GPIOD_BASE + MO_OFFSET_R	))

#define OD_R_OFFSET   		(0x14UL)
#define GPIOD_OD_R 		(*(volatile unsigned  int *)(GPIOD_BASE + OD_R_OFFSET ))

#define GPIOD_BSRR              (*(volatile unsigned int *)(GPIOD_BASE +OFFSET_BSRR ))
#define GPIOD_IDR               (*(volatile unsigned int *)(GPIOD_BASE +OFFSET_IDR  ))


void InputOutputConfig (void )
{
  
	RCC_AHB1EN_R  |=  GPIODEN; /*ENABLE clock access to gpioD*/

	
	GPIOD_MODE_R |=(1U<<30);   /*2. set PIN15 as OUTPUT */
	GPIOD_MODE_R &=~(1U<<31);
        GPIOD_MODE_R |=(1U<<24);   /*2. set PIN12 as OUTPUT */
	GPIOD_MODE_R &=~(1U<<25);
        
}
 void ButtonToggleLed (void)
 {
    while(1)
    
    {
        

         if( GPIOD_IDR  & BUUTON_GREEN_INPUT)
         {
    	 GPIOD_BSRR  = BUUTON_GREEN_INPUT ;
         }
    	 else
         {
           
         GPIOD_BSRR  = (1U<<28);
          
    	 }

   GPIOD_OD_R  |=  LED_BLUE_PIN;

     }
 }
   

        

   
