#include "argument_parser.h"
#include "tcp_client.h"
#include "http_testing_request_sender.h"
#include "response_processor.h"

void deinitialise(input_data_t* input_data) {
	free(input_data->host_name);
	free(input_data->resource_path);
}

int main(int argc, char* argv[]) {
	input_data_t input_data;
	parse_and_validate_arguments(argc, argv, &input_data);
	int socket_fd = establish_tcp_connection(&input_data);

	send_http_testing_request(socket_fd, &input_data);
	process_server_response_and_report(socket_fd);

	deinitialise(&input_data);

	// TODO Skrypt
	printf("\nSuccess.\n");
}