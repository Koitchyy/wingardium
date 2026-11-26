#include "status_led.h"
// may want to update to use timer interrupts instead for blink

// should be initialized in main.c from cubemx code
//__HAL_RCC_GPIOB_CLK_ENABLE();
//__HAL_RCC_GPIOC_CLK_ENABLE();


void status_led_set(StatusLed *led, GPIO_PinState state)
{
    led->toggle_interval_ms = 0;
    HAL_GPIO_WritePin(led->port, led->pin, state);
}

void status_led_toggle(StatusLed *led)
{
    led->toggle_interval_ms = 0;
    HAL_GPIO_TogglePin(led->port, led->pin);
}

void status_led_blink(StatusLed *led, uint32_t toggle_interval_ms)
{
    led->toggle_interval_ms = toggle_interval_ms;
    led->last_toggle_ms = HAL_GetTick();
    HAL_GPIO_WritePin(led->port, led->pin, GPIO_PIN_SET);
}

// call in superloop
void status_led_update(StatusLed *led)
{
    if (led->toggle_interval_ms == 0) {
        return;
    }

    uint32_t now_ms = HAL_GetTick();

    if (now_ms - led->last_toggle_ms >= led->toggle_interval_ms) {
        HAL_GPIO_TogglePin(led->port, led->pin);
        led->last_toggle_ms = now_ms;
    }
}
