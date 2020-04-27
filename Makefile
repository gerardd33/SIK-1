CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2

.PHONY: all clean

all: testhttp_raw

testhttp_raw: testhttp_raw.o argument_parser.o tcp_client.o http_testing_request_sender.o response_processor.o
	$(CC) -o testhttp_raw $^

testhttp_raw.o: testhttp_raw.c argument_parser.h tcp_client.h http_testing_request_sender.h response_processor.h
	$(CC) $(CFLAGS) -c $<

err.o: err.c err.h
	$(CC) $(CFLAGS) -c $<

argument_parser.o: argument_parser.c argument_parser.h input_data.h
	$(CC) $(CFLAGS) -c $<

tcp_client.o: tcp_client.c tcp_client.h input_data.h
	$(CC) $(CFLAGS) -c $<

http_testing_request_sender.o: http_testing_request_sender.c http_testing_request_sender.h input_data.h
	$(CC) $(CFLAGS) -c $<

response_processor.o: response_processor.c response_processor.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o testhttp_raw