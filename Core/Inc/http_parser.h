/*
 * http_parser.h
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_HTTP_PARSER_H_
#define INC_HTTP_PARSER_H_

#include "stdbool.h"
#include "http.h"

int parse_http_request(const uint8_t *buffer, size_t buffer_len, HTTP_REQUEST *request);
bool http_method_is(const HTTP_REQUEST *request, const char *method_str);
bool is_path_match(const char* path, const HTTP_REQUEST *const request);
bool is_query_path(const HTTP_REQUEST* request, const char* prefix);
void extract_query_param(char* dest, const HTTP_REQUEST* request, const char* prefix);


#endif /* INC_HTTP_PARSER_H_ */
