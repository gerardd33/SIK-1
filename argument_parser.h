#ifndef ARGUMENT_PARSER_H_
#define ARGUMENT_PARSER_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "err.h"

// Resource path is stored without the initial '/'. We have to add it before the request.
typedef struct input_data {
	char* connection_address;
	char* connection_port;
	char* cookie_file_name;
	char* host_name;
	char* resource_path;
} input_data_t;

// Puts data from parsed arguments under passed pointer to an input_data struct.
// Exits if there is an error while parsing or validating.
void parse_and_validate_arguments(int argc, char* argv[], input_data_t* input_data);

#endif //ARGUMENT_PARSER_H_
