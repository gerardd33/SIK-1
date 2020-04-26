#include "http_testing_request_sender.h"

const char* CRLF = "\r\n";

// TODO pozmieniaj wszedzie stdout na socket_fd
static void send_initial_headers(int socket_fd, input_data_t* input_data) {
	fprintf(stdout, "GET /%s HTTP/1.1\r\n"
									 "Host: %s\r\n"
									 "User-Agent: testhttp_raw\r\n"
									 "Connection: close\r\n",
										input_data->resource_path,
										input_data->host_name);

	int fprintf_result = fprintf(stdout, "%s", CRLF);
	if (fprintf_result != strlen(CRLF))
		fatal("sending http request");
}

static void send_cookies(int socket_fd) {

}

static void end_request(int socket_fd) {
	int fprintf_result = fprintf(stdout, "%s", CRLF);
	if (fprintf_result != strlen(CRLF))
		fatal("sending http request");
}

void send_http_testing_request(int socket_fd, input_data_t* input_data) {
	send_initial_headers(socket_fd, input_data);
	send_cookies(socket_fd);
	end_request(socket_fd);
}