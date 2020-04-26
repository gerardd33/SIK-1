#include "tcp_client.h"

static struct addrinfo* get_addrinfo_from_string(char* connection_address, char* connection_port) {
	struct addrinfo address_hints;
	struct addrinfo* address_result;

	memset(&address_hints, 0, sizeof(struct addrinfo));
	address_hints.ai_family = AF_INET;
	address_hints.ai_socktype = SOCK_STREAM;
	address_hints.ai_protocol = IPPROTO_TCP;
	if (getaddrinfo(connection_address, connection_port, &address_hints, &address_result) != 0)
		fatal("failed to establish tcp connection");

	return address_result;
}

FILE* establish_tcp_connection(input_data_t* input_data) {
	struct addrinfo* address_info = get_addrinfo_from_string(input_data->connection_address,
																														input_data->connection_port);

	int socket_fd = socket(address_info->ai_family, address_info->ai_socktype, address_info->ai_protocol);
	if (socket_fd < 0)
		syserr("socket");

	if (connect(socket_fd, address_info->ai_addr, address_info->ai_addrlen) < 0)
		syserr("connect");

	freeaddrinfo(address_info);

	FILE* socket_file = fdopen(socket_fd, "r+");
	return socket_file;
}