/*
 * uart_utils.c
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */
#include "uart_utils.h"

extern UART_HandleTypeDef huart1;

uint8_t rx_buffer[RX_BUFFER_SIZE];
uint16_t rx_index = 0;


bool is_end_of_header(void) {
    return rx_index >= 4 &&
           rx_buffer[rx_index - 4] == '\r' &&
           rx_buffer[rx_index - 3] == '\n' &&
           rx_buffer[rx_index - 2] == '\r' &&
           rx_buffer[rx_index - 1] == '\n';
}

bool is_rx_index_valid(int rx_index) {
    return rx_index < RX_BUFFER_SIZE - 1;
}

HAL_StatusTypeDef uart_wait_for_byte(uint8_t *byte) {
	return HAL_UART_Receive(&huart1, byte, 1, HAL_MAX_DELAY) == HAL_OK;
}

void http_buffer_add_byte(uint8_t byte) {
	if (is_rx_index_valid(rx_index)) {
		rx_buffer[rx_index++] = byte;
	}
}
void uart_receive_http_byte(void) {
	uint8_t byte;
	if (uart_wait_for_byte(&byte)){
		http_buffer_add_byte(byte);
	}
}
