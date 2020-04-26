#include "argument_parser.h"
#include "tcp_client.h"
#include "http_testing_request_sender.h"
#include "response_processor.h"

int main(int argc, char* argv[]) {
	// TODO Sparsuj i zwaliduj argumenty
	input_data_t input_data;
	parse_and_validate_arguments(argc, argv, &input_data);

	int socket_fd = establish_tcp_connection(&input_data);

	send_http_testing_request(socket_fd, &input_data);

	process_server_response_and_report(socket_fd);

	// TODO Skrypt

	printf("\nSuccess.\n");
}