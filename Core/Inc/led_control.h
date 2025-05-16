/*
 * led_control.h
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include "http.h"
#include "stm32f1xx_hal.h"

void process_led_control(const HTTP_REQUEST *const http_request);
void handle_led_off(GPIO_PinState pin);

#endif /* INC_LED_CONTROL_H_ */
