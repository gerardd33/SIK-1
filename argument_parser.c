#include "argument_parser.h"

static const char* HTTP_STRING = "http";
static const char* HTTPS_STRING = "https";

static void parse_and_validate_address_and_port(char* string_to_parse, input_data_t* input_data) {
	char* separator_position_pointer = strchr(string_to_parse, ':');
	if (separator_position_pointer == NULL) {
		fatal("invalid address/port");
	}

	*separator_position_pointer = 0;
	++separator_position_pointer;

	input_data->connection_address = string_to_parse;
	input_data->connection_port = separator_position_pointer;
}

static void parse_and_validate_http_tested_address(char* string_to_parse, input_data_t* input_data) {
	char protocol_type[strlen(HTTPS_STRING) + 1];
	// Check if sscanf read one item properly.
	if (sscanf(string_to_parse, "%[^:]", protocol_type) != 1) {
		fatal("invalid http tested address");
	}

	bool is_https = false;
	if (strcmp(protocol_type, HTTP_STRING) != 0) {
		if (strcmp(protocol_type, HTTPS_STRING) != 0) {
			fatal("invalid http tested address");
		} else {
			is_https = true;
		}
	}

	input_data->host_name = NULL;
	input_data->resource_path = NULL;
	int sscanf_result = is_https ?
			sscanf(string_to_parse, "https://%m[^/]/%ms",
							&(input_data->host_name), &(input_data->resource_path))
			: sscanf(string_to_parse, "http://%m[^/]/%ms",
							&(input_data->host_name), &(input_data->resource_path));

	if (sscanf_result == 0) {
		fatal("invalid http tested address");
	}
}

void parse_and_validate_arguments(int argc, char* argv[], input_data_t* input_data) {
	if (argc != 4) {
		fatal("invalid argument count");
	}

	parse_and_validate_address_and_port(argv[1], input_data);
	input_data->cookie_file_name = argv[2];
	parse_and_validate_http_tested_address(argv[3], input_data);
}