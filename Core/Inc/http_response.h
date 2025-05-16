/*
 * http_response.h
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_HTTP_RESPONSE_H_
#define INC_HTTP_RESPONSE_H_

#include <inttypes.h>
#include <stdlib.h>
#include "stm32f1xx_hal.h"

#define HTML_RESPONSE_HEADER \
    "HTTP/1.0 200 OK\r\n" \
    "Content-Type: text/html\r\n" \
    "Content-Length: %d\r\n" \
    "Connection: close\r\n" \
    "\r\n%s"

#define HTML_RESPONSE_NO_CONTENT_HEADER \
    "HTTP/1.0 200 No Content\r\n" \
    "Connection: close\r\n" \
    "\r\n"

typedef struct {
	char *response;
	uint16_t content_lenght;
} HTTP_RESPONSE;

HTTP_RESPONSE generate_http_response(const char* header, const char* html_content);
void send_http_response(HTTP_RESPONSE http_response);
void send_html_response(const char *const header, const char* body);

#endif /* INC_HTTP_RESPONSE_H_ */
