#ifndef RESPONSE_PROCESSOR_H_
#define RESPONSE_PROCESSOR_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "err.h"

void process_server_response_and_report(int socket_fd);

#endif //RESPONSE_PROCESSOR_H_
