/*
 * Button.c
 *
 *  Created on: Jun 20, 2014
 *      Author: Administrator
 */
#include "Button.h"
#include "derivative.h"

void Init_PA_int()
{
    //this function initializes the interrupt generation from port A
    
	NVIC_ICER |= (1<<(30%32));//clear enable register for IQR 30 which is PORTA
	NVIC_ISER |= (1<<(30%32));//Interrupt Set enable register for IRQ 30 (which is the Port A interrupt)
}

void PORTA_IRQHandler()
{
    //This function is the interrupt handler for port A (where our GPIO pin is!)
    
    //Whenever the interrupt is generated we toggle our RED_LED (that's defined in Button.h
	GPIOB_PTOR = RED_LED;
    
    //Now set the interrupt status flag register to indiciate that the interrupt has been generated
    //without this step, the program loops through that handler
	PORTA_ISFR = 0xFFFFFFFF;
}
