#ifndef HTTP_TESTING_REQUEST_SENDER_H_
#define HTTP_TESTING_REQUEST_SENDER_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "err.h"
#include "input_data.h"

void send_http_testing_request(int socket_fd, input_data_t* input_data);

#endif //HTTP_TESTING_REQUEST_SENDER_H_
