#include "http_testing_request_sender.h"

// Takes two string arguments: resource path and host name.
static const char* INITIAL_HEADERS_FORMAT = "GET %s HTTP/1.1\r\n"
																						 "Host: %s\r\n"
																						 "User-Agent: testhttp_raw\r\n"
																						 "Connection: close\r\n";

static void send_initial_headers(FILE* socket_file, input_data_t* input_data) {
	if (fprintf(socket_file, INITIAL_HEADERS_FORMAT, input_data->resource_path, input_data->host_name) < 0) {
		syserr("fprintf");
	}
}

static void trim_line(char* line) {
	while (*line != '\n') {
		++line;
	}
	*line = 0;
}

static void send_cookies(FILE* socket_file, input_data_t* input_data) {
	FILE* cookie_file = fopen(input_data->cookie_file_name, "r");
	if (cookie_file == NULL) {
		fatal("opening cookie file");
	}

	char* line = NULL;
	size_t buffer_size = 0;
	bool first_cookie = true;

	while (true) {
		if (getline(&line, &buffer_size, cookie_file) == -1) {
			break;
		}
		// TODO zrob dobrze handling bledow getline'a

		trim_line(line);
		if (first_cookie) {
			if (fprintf(socket_file, "Cookie: %s", line) < 0) {
				syserr("fprintf");
			}
			first_cookie = false;
		} else if (fprintf(socket_file, "; %s", line) < 0) {
				syserr("fprintf");
			}
		}

	if (!first_cookie) {
		if (fprintf(socket_file, "\r\n") < 0) {
			syserr("fprintf");
		}
	}

	free(line);
	fclose(cookie_file);
}

static void end_request(FILE* socket_file) {
	if (fprintf(socket_file, "\r\n") < 0) {
		fatal("sending http request");
	}
}

void send_http_testing_request(FILE* socket_file, input_data_t* input_data) {
	send_initial_headers(socket_file, input_data);
	send_cookies(socket_file, input_data);
	end_request(socket_file);
}