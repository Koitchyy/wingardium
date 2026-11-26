#include "state_machine.h"
#include "statusLED.h"

static States state = DISABLED;
static StatusLED

static void onStateEntry(States entered) {
	if (enetered == DISABLED) {
		status
	}
}

const char *stateToString(States state) {
	switch (state) {
		case DISABLED:
			return "DISABLED";
		case CALIBRATING:
			return "CALIBRATING";
		case FAULT:
			return "FAULT";
		case ENABLED:
			return "ENABLED";
		default:
			return "DISABLED";
	}
}

static States handleDisabled(bool button_pressed) {
	// if rising edge on button => state = calibrate



	if (button_pressed) {
		return CALIBRATING;
	}

	return DISABLED;
}

static States handleCalibrating() {
	// if calibratesuccess == 0 => enabled
	// if calibratesuccess == 0 => disabled


}

static States handleFault() {
	// display which fault it is

}
static States handleEnabled() {
	// run the simulation
}


void updateState() {
	switch (state) {
		case DISABLED:
			state = handleDisabled();
			break;
		case CALIBRATING:
			state = handleCalibrating();
			break;
		case FAULT:
			state = handleFault();
			break;
		case ENABLED:
			state = handleEnabled();
			break;
		default:
			state = DISABLED;
			break;
	}
}
