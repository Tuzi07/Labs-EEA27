/*
 * Copyright (c) 2019 Sturulosa Inc.
 */

#include "./rgb/hal_rgbled.h"

/*Define function currentState STITCHEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/
int * currentState;

int main(void) {
	/*Setup*/
	hal_rgbled__setupRgbLed();
	/*Init the state machine*/
	/* Never leave main */
	int state = RED;
	currentState = & state;

	while (1) {
		hal_rgbled__trafficLight(currentState);
	}

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
// Cabou :(
////////////////////////////////////////////////////////////////////////////////
