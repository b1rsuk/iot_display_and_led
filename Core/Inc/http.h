/*
 * http.h
 *
 *  Created on: 17 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_HTTP_H_
#define INC_HTTP_H_

#include <stdlib.h>
#include <inttypes.h>

#include "picohttpparser.h"

#define MAX_HEADERS 20

typedef struct {
    const char *method;
    size_t method_len;
    const char *path;
    size_t path_len;
    int minor_version;
    struct phr_header headers[MAX_HEADERS];
    size_t num_headers;
} HTTP_REQUEST;

void http_handler(void);

#endif /* INC_HTTP_H_ */
