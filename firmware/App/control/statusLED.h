#ifndef STATUS_LED_H
#define STATUS_LED_H

#include "stm32l4xx_hal.h"

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    uint32_t toggle_interval_ms;  // 0 means steady mode
    uint32_t last_toggle_ms;
} StatusLed;

void status_led_set(StatusLed *led, GPIO_PinState state);
void status_led_toggle(StatusLed *led);
void status_led_blink(StatusLed *led, uint32_t toggle_interval_ms);
void status_led_update(StatusLed *led);

#endif
