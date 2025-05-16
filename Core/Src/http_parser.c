#include "http_parser.h"

bool http_method_is(const HTTP_REQUEST *request, const char *method_str) {
    size_t expected_len = strlen(method_str);
    return request->method_len == expected_len &&
           strncmp(request->method, method_str, expected_len) == 0;
}

bool is_path_match(const char* path, const HTTP_REQUEST *const request) {
    size_t path_len = strlen(path);
    return request->path_len == path_len &&
           strncmp(path, request->path, path_len) == 0;
}

bool is_query_path(const HTTP_REQUEST* request, const char* prefix) {
	return request->path_len >= strlen(prefix) &&
	       !memcmp(request->path, prefix, strlen(prefix));
}

int parse_http_request(const uint8_t *buffer, size_t buffer_len, HTTP_REQUEST *request) {
    request->num_headers = MAX_HEADERS;

    int pret = phr_parse_request(
        (const char *)buffer,
        buffer_len,
        &request->method,
        &request->method_len,
        &request->path,
        &request->path_len,
        &request->minor_version,
        request->headers,
        &request->num_headers,
        0
    );

    return pret;
}

void extract_query_param(char* dest, const HTTP_REQUEST* request, const char* prefix) {
	size_t prefix_len = strlen(prefix);
	size_t len = request->path_len - prefix_len;
	memmove(dest, request->path + prefix_len, len);
	dest[len] = '\0';
}

