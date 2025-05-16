/*
 * led_control.c
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#include "led_control.h"
#include "http_response.h"

void handle_led_off(GPIO_PinState pin) {
	HAL_GPIO_WritePin(GPIOA, pin, GPIO_PIN_RESET);
	send_html_response(HTML_RESPONSE_NO_CONTENT_HEADER, NULL);
}

void process_led_control(const HTTP_REQUEST *const http_request) {
	struct {
		const char *path;
		uint16_t pin;
		GPIO_PinState state;
	} commands[] = {
		{ "/led1_on",  GPIO_PIN_4, GPIO_PIN_SET },
		{ "/led1_off", GPIO_PIN_4, GPIO_PIN_RESET },
		{ "/led2_on",  GPIO_PIN_5, GPIO_PIN_SET },
		{ "/led2_off", GPIO_PIN_5, GPIO_PIN_RESET },
		{ "/led3_on",  GPIO_PIN_6, GPIO_PIN_SET },
		{ "/led3_off", GPIO_PIN_6, GPIO_PIN_RESET },
		{ "/led4_on",  GPIO_PIN_7, GPIO_PIN_SET },
		{ "/led4_off", GPIO_PIN_7, GPIO_PIN_RESET },
	};

	for (int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++) {
		if (is_path_match(commands[i].path, http_request)) {
			HAL_GPIO_WritePin(GPIOA, commands[i].pin, commands[i].state);
			send_html_response(HTML_RESPONSE_NO_CONTENT_HEADER, NULL);
			return;
		}
	}
}

