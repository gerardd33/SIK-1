#include "response_processor.h"

// Returns true if status is "200 OK". Returns false and prints the status line otherwise.
static bool read_status_line(FILE* socket_file) {
	char* status_message = NULL;
	int http_version, status_code;

	fscanf(socket_file, "HTTP/1.%d %d %ms\r\n", &http_version, &status_code, &status_message);
	if (status_code != 200 || strcmp(status_message, "OK") != 0) {
		printf("HTTP/1.%d %d %s\n", http_version, status_code, status_message);
		free(status_message);
		return false;
	}

	free(status_message);
	return true;
}

static void convert_header_name_to_lowercase(char* line) {
	for (size_t index = 0; line[index] != 0 && line[index] != ':'; ++index) {
		line[index] = (char)tolower(line[index]);
	}
}

static bool check_if_chunked(char* line, char** header_value) {
	sscanf(line, "transfer-encoding: %m[^\r\n]", header_value);
	return (*header_value != NULL || strstr(*header_value, "chunked") != NULL);
}

static void check_if_cookie_and_write(char* line, char** cookie) {
	sscanf(line, "set-cookie: %m[^;\r\n ]", cookie);
	if (*cookie != NULL)
		printf("%s\n", *cookie);
}

static void parse_headers_and_write_cookies(FILE* socket_file, bool* chunked) {
	char* line = NULL;
	char* parsed_header = NULL;
	size_t buffer_size = 0;
	ssize_t getline_result = 0;
	*chunked = false;

	while (true) {
		if (getline(&line, &buffer_size, socket_file) == -1)
			syserr("getline");

		if (strcmp(line, "\r\n") == 0)
			break;

		convert_header_name_to_lowercase(line);
		if (check_if_chunked(line, &parsed_header))
			*chunked = true;
		else check_if_cookie_and_write(line, &parsed_header);
	}

	free(parsed_header);
	free(line);
}

static void find_and_write_resource_length(FILE* socket_file, bool chunked) {

}

void process_server_response_and_report(FILE* socket_file) {
	if (!read_status_line(socket_file))
		return;

	bool chunked;
	parse_headers_and_write_cookies(socket_file, &chunked);
	find_and_write_resource_length(socket_file, chunked);
}