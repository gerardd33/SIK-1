#ifndef RESPONSE_PROCESSOR_H_
#define RESPONSE_PROCESSOR_H_

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"

void process_server_response_and_report(FILE* socket_file);

#endif  // RESPONSE_PROCESSOR_H_
