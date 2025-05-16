/*
 * uart_utils.h
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_UART_UTILS_H_
#define INC_UART_UTILS_H_
#include <inttypes.h>
#include <stdbool.h>

#include "stm32f1xx_hal.h"

#define RX_BUFFER_SIZE 1024

HAL_StatusTypeDef uart_wait_for_byte(uint8_t *);
void http_buffer_add_byte(uint8_t);
void uart_receive_http_byte(void);
bool is_end_of_header(void);
bool is_rx_index_valid(int);


#endif /* INC_UART_UTILS_H_ */
