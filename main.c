#include "derivative.h" /* include peripheral declarations */
#include "Button.h" //include the button file

int main(void)
{
    //first gate the proper clock.
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK;
    //now configure the on board LED through it's gpio port. enable drives strength too.
	PORTB_PCR18 = PORT_PCR_MUX(1)|PORT_PCR_DSE_MASK;
    //now configure your pin that's to be used for GPIO input.
    //The port must have an interrupt enabled IRQC (see reference manual for this)
	PORTA_PCR16 = PORT_PCR_MUX(1) | PORT_PCR_IRQC(0x09);
    
    //Now initialize the button (PA means port A <-- that's where our button will be)
	Init_PA_int();
	
    //Now set the port data direction. By default this is set to input. Therefore we only have to change it for our onboard button.
	GPIOB_PDDR |= RED_LED;
	
    //Main loop... that does nothing because our interrupt handler does it all!
	for(;;)
	{
     //nop 
	}
	
	return 0;
}
