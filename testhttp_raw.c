#include "argument_parser.h"
#include "tcp_client.h"
#include "http_testing_request_sender.h"

int main(int argc, char* argv[]) {
	// TODO Sparsuj i zwaliduj argumenty
	input_data_t input_data;
	parse_and_validate_arguments(argc, argv, &input_data);

	int socket_fd = establish_tcp_connection(input_data.connection_address, input_data.connection_port);

	send_http_testing_request(socket_fd, &input_data);

	// TODO Przeslij requesta http do serwera

	// TODO Wczytaj wiersz statusu z reponse'a serwera (pierwsza linia)

	// TODO Jesli inny niz 200 OK, wypisz te pierwsza linie, zakoncz program

	// TODO Znajdz ciasteczka, wypisz je na stdout

	// TODO Znajdz dlugosc zasobu, wypisz ja na stdout

	// TODO Skrypt

	printf("\nSuccess.\n");
}