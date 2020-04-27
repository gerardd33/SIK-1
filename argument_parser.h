#ifndef ARGUMENT_PARSER_H_
#define ARGUMENT_PARSER_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "err.h"
#include "input_data.h"

// Puts data from parsed arguments under passed pointer to an input_data struct.
// Exits if there is an error while parsing or validating.
void parse_and_validate_arguments(int argc, char* argv[], input_data_t* input_data);

#endif // ARGUMENT_PARSER_H_
