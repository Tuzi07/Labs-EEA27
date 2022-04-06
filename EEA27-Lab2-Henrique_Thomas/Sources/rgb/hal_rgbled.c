#include "fsl_device_registers.h"
#define CLEAR_CLOCK     0xffffe1ff
#define SET_CLOCK       0x00000400
#define CLEAR_INTERRUPT 0xfffff8ff
#define SET_INTERRUPT   0x00000100
#define CLEAR_OUTPUT    0x00000000
#define SET_OUTPUT      0x000c0000
#define SET_RED         0x00040000
#define SET_GREEN       0x00080000

enum color
{
	RED,GREEN,YELLOW
};

/*Enable clock gating setup PORT mux, and setup GPIO data direction*/
void hal_rgbled__setupRgbLed()
{
	SIM_SCGC5   &=  (CLEAR_CLOCK);
	SIM_SCGC5   |=  (SET_CLOCK);
	PORTB_PCR18 &=  (CLEAR_INTERRUPT);
	PORTB_PCR18 |=  (SET_INTERRUPT);
	PORTB_PCR19 &=  (CLEAR_INTERRUPT);
	PORTB_PCR19 |=  (SET_INTERRUPT);
	GPIOB_PDDR  &=  (CLEAR_OUTPUT);
	GPIOB_PDDR  |=  (SET_OUTPUT);
}
/*To set red light in rgb led*/
void hal_rgbled__setLedRed()
{
	//FGPIOB_PSOR&=CLEAR_OUTPUT
	FGPIOB_PSOR |= SET_RED;
}
/*To set green light in rgb led*/
void hal_rgbled__setLedGreen()
{
	//FGPIOB_PSOR &= CLEAR_OUTPUT
	FGPIOB_PSOR |= SET_GREEN;
}
/*To set blue light in rgb led*/

/*To clear blue light in rgb led*/
void hal_rgbled__clearLedRed()
{
	//FGPIOB_PCOR  &= CLEAR_OUTPUT
	FGPIOB_PCOR |= SET_RED;
}
/*To clear blue light in rgb led*/
void hal_rgbled__clearLedGreen()
{
	////FGPIOB_PCOR&=CLEAR_OUTPUT
	FGPIOB_PCOR|=SET_GREEN;
}
/*To clear blue light in rgb led*/


/*Delay N seconds*/
void hal_rgbled__delayNSeconds(int n)
{
	for(int i = 0; i < 1000000*n; ++i);
}

/*Implement the finite state machine*/
void hal_rgbled__trafficLight(int* currentState)
{
	switch(*currentState)
	{
		case RED:
			hal_rgbled__setLedGreen();
			hal_rgbled__clearLedRed();
			hal_rgbled__delayNSeconds(3);
			*currentState = GREEN;
			break;

		case GREEN:
			hal_rgbled__setLedRed();
			hal_rgbled__clearLedGreen();
			hal_rgbled__delayNSeconds(4);
			*currentState = YELLOW;
			break;
		case YELLOW:
			hal_rgbled__clearLedRed();
			hal_rgbled__delayNSeconds(2);
			*currentState = RED;
			break;
		default:
			break;

	}
}
