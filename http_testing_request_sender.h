#ifndef HTTP_TESTING_REQUEST_SENDER_H_
#define HTTP_TESTING_REQUEST_SENDER_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "input_data.h"

void send_http_testing_request(FILE* socket_file, input_data_t* input_data);

#endif  // HTTP_TESTING_REQUEST_SENDER_H_
