#include "argument_parser.h"


static void parse_and_validate_address_and_port(char* string_to_parse, input_data_t* input_data) {
	char* separator_position_pointer = strchr(string_to_parse, ':');
	if (separator_position_pointer == NULL)
		fatal("invalid first argument");

	*separator_position_pointer = 0;
	++separator_position_pointer;

	input_data->connection_address = string_to_parse;
	input_data->connection_port = separator_position_pointer;

	printf("adres:%s\n", input_data->connection_address);
	printf("port:%s\n", input_data->connection_port);
}

static void parse_and_validate_http_tested_address(char* string_to_parse, input_data_t* input_data) {
	char* separator_position_pointer = strchr(string_to_parse, '/');
	if (separator_position_pointer == NULL)
		fatal("invalid third argument");

	++separator_position_pointer; // Second '/' in "http://".
	*separator_position_pointer = 0;
	++separator_position_pointer;
	input_data->host_name = separator_position_pointer;

	printf("host:%s\n", input_data->host_name);
	separator_position_pointer = strchr(separator_position_pointer, '/'); // Find the first '/' after host's name.
	if (separator_position_pointer == NULL)
		fatal("invalid third argument");

	*separator_position_pointer = 0;
	++separator_position_pointer;
	input_data->resource_path = separator_position_pointer;
	printf("resource:%s\n", input_data->resource_path);
}

// Puts data from parsed arguments under passed pointer to an input_data struct.
// Exits if there is an error while parsing or validating.
void parse_and_validate_arguments(int argc, char* argv[], input_data_t* input_data) {
	if (argc != 4)
		fatal("invalid argument count");

	parse_and_validate_address_and_port(argv[1], input_data);
	input_data->cookie_file_name = argv[2];
	parse_and_validate_http_tested_address(argv[3], input_data);
}