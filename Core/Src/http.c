/*
 * http.c
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#include "http.h"
#include <string.h>
#include "http_response.h"
#include "root_html.h"
#include "ssd1306.h"
#include "root_html.h"

extern uint8_t rx_buffer[];
extern uint16_t rx_index;

static void handle_root_request(void) {
	send_html_response(HTML_RESPONSE_HEADER, LED_CONTROLLER_HTML);
}

static void handle_send_text(const HTTP_REQUEST* request) {
	const char* prefix = "/send_text?msg=";
	size_t prefix_len = strlen(prefix);

	char text[request->path_len - prefix_len + 1];
	extract_query_param(text, request, prefix);

	ssd1306_Clear();
	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString(text, Font_7x10);
	ssd1306_UpdateScreen();

	send_html_response(HTML_RESPONSE_NO_CONTENT_HEADER, NULL);
}

static void handle_get_request(const HTTP_REQUEST *request) {
    if (is_path_match("/", request)) {
        handle_root_request();
    }
    else if (is_query_path(request, "/send_text?msg=")) {
        handle_send_text(request);
    }
}

static void handle_post_request(const HTTP_REQUEST *request) {
    process_led_control(request);
}


static void handle_http_header_end(void) {
	if (is_end_of_header()) {
		rx_buffer[rx_index] = '\0';

		HTTP_REQUEST http_request;
		parse_http_request(rx_buffer, rx_index, &http_request);

		if (http_method_is(&http_request, "GET")) {
			handle_get_request(&http_request);
		}

		else if (http_method_is(&http_request, "POST")) {
			handle_post_request(&http_request);
		}

		memset(rx_buffer, 0, rx_index);
		rx_index = 0;
	}
}

void http_handler(void)
{
	uart_receive_http_byte();
	handle_http_header_end();
}
