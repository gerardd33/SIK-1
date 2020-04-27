#ifndef TCP_CLIENT_H_
#define TCP_CLIENT_H_

#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "err.h"
#include "input_data.h"

// Returns the socket descriptor.
int establish_tcp_connection(input_data_t* input_data);

#endif  // TCP_CLIENT_H_
