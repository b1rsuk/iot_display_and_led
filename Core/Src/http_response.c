/*
 * http_response.c
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#include "http_response.h"

extern UART_HandleTypeDef huart1;

HTTP_RESPONSE generate_http_response(const char* header, const char* html_content) {

	int html_len = (html_content != NULL) ? strlen(html_content) : 0;
    int header_len = strlen(header);

    int response_size = header_len + html_len;
    char *response = calloc(1, response_size + 1 + 128);

    if (html_content != NULL) {
        snprintf(response, response_size + 1, header, html_len, html_content);
    } else {
        snprintf(response, response_size + 1, header, 0, "");
    }

    HTTP_RESPONSE http_response = {.response = response, .content_lenght = response_size};
    return http_response;
}

void send_http_response(HTTP_RESPONSE http_response) {
	HAL_UART_Transmit(&huart1, (const uint8_t *) http_response.response, http_response.content_lenght, HAL_MAX_DELAY);
}

void send_html_response(const char *const header, const char* body) {
    HTTP_RESPONSE http_response = generate_http_response(header, body);
    send_http_response(http_response);
    free(http_response.response);
}
