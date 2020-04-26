#include "response_processor.h"

// Returns true if status is "200 OK". Returns false and prints the status line otherwise.
static bool read_status_line(FILE* socket_file) {
	char* status_message = NULL;
	int http_version, status_code;

	fscanf(socket_file, "HTTP/1.%d %d %ms\r\n", &http_version, &status_code, &status_message);
	if (status_code != 200 || strcmp(status_message, "OK") != 0) {
		printf("HTTP/1.%d %d %s\r\n", http_version, status_code, status_message);
		return false;
	}

	return true;
}

static void find_and_write_cookies(FILE* socket_file) {

}

void process_server_response_and_report(int socket_fd) {
	FILE* socket_file = fdopen(socket_fd, "r");

	if (!read_status_line(socket_file))
		return;

	find_and_write_cookies(socket_file);

	// TODO Znajdz dlugosc zasobu, wypisz ja na stdout
}