#ifndef TCP_CLIENT_H_
#define TCP_CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>
#include "err.h"

// Returns the socket descriptor.
int establish_tcp_connection(char* connection_address, char* connection_port);

#endif //TCP_CLIENT_H_
