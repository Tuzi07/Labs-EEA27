/*
 * hal_rgbled.h
 *
 *  Created on: 05/04/2022
 *      Author: Henrique
 */


#ifndef SOURCES_HAL_RGBLED_H_
#define SOURCES_HAL_RGBLED_H_

enum color
{
	RED,GREEN,YELLOW
};

/*Enable clock gating setup PORT mux, and setup GPIO data direction*/
void hal_rgbled__setupRgbLed();
/*To set red light in rgb led*/
void hal_rgbled__setLedRed();
/*To set green light in rgb led*/
void hal_rgbled__setLedGreen();
/*To set blue light in rgb led*/
void hal_rgbled__setLedBlue();
/*To clear blue light in rgb led*/
void hal_rgbled__clearLedRed();
/*To clear blue light in rgb led*/
void hal_rgbled__clearLedGreen();
/*To clear blue light in rgb led*/
void hal_rgbled__clearLedBlue();
/*Delay N seconds*/
void hal_rgbled__delayNSeconds(int n);
/*Implement the finite state machine*/
void hal_rgbled__trafficLight(int* currentState);

#endif /* SOURCES_HAL_RGBLED_H_ */
