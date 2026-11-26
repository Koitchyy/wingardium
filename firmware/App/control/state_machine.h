#pragma once

enum States {DISABLED, CALIBRATING, FAULT, ENABLED}

const char *stateToString(States state);

void updateState();


