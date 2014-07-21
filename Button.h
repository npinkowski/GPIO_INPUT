/*
 * Button.h
 *
 *  Created on: Jun 20, 2014
 *      Author: Administrator
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#define RED_LED     (1<<18)

void Init_PA_int();
void PORTA_IRQHandler();


#endif /* BUTTON_H_ */
