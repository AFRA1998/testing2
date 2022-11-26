/**
  ******************************************************************************
  * @file    main.c
  * @author  AFRA MABROUK
  * @brief   GPIO
  * @version V1.0.0
  * @date    16-10-2022
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"


#include "LED.h"

int main()
{

 GPIO_Clock_Enable(GPIOD);
 InputOutputConfig();
 ButtonToggleLed ();
 
 
GPIO_Config (GPIOD,PIN12,OUTPUT,OUTPUT_PUSH_PULL,LOW_SPEED);
GPIO_Config (GPIOD,PIN12,INPUT,OUTPUT_OPEN_DRAIN,LOW_SPEED);
GPIO_Write_Pin(GPIOD, PIN12, SET);
GPIO_Write_Pin(GPIOD, PIN12, RESET);

uint8_t GPIOPinTest = GPIO_READ_Pin(GPIOD,PIN10);

  while(1)
  {
  }
}

 

/**************************************END OF FILE**************************************/
