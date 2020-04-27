#ifndef ARGUMENT_PARSER_H_
#define ARGUMENT_PARSER_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "input_data.h"

void parse_and_validate_arguments(int argc, char* argv[],
                                  input_data_t* input_data);

#endif  // ARGUMENT_PARSER_H_
