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

static void find_and_write_cookies(FILE* socket_file) {
	char* line = NULL;
	size_t buffer_size = 0;
	ssize_t getline_result = 0;

	while (true) {
		if (getline(&line, &buffer_size, socket_file) == -1)
			break;
		// TODO zrob dobrze handling bledow getline'a

		for (size_t index = 0; line[index] != 0 && line[index] != ':'; ++index) {
			line[index] = (char)tolower(line[index]);
		}

		// TODO czy tu moga byc w koncu inne delimitery? ','? ' '?
		char* cookie = NULL;
		sscanf(line, "set-cookie: %m[^;\r\n]", &cookie);
		if (cookie != NULL)
			printf("%s\n", cookie);
		free(cookie);
	}

	free(line);
}

static void find_and_write_resource_length(FILE* socket_file) {

}

void process_server_response_and_report(FILE* socket_file) {
	if (!read_status_line(socket_file))
		return;

	find_and_write_cookies(socket_file);
	find_and_write_resource_length(socket_file);
}