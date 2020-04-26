#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "err.h"


// Resource path is stored without the initial '/'. We have to add it before the request.
typedef struct input_data {
	char* connection_address;
	char* connection_port;
	char* cookie_file_name;
	char* host_name;
	char* resource_path;
} input_data_t;


void parse_and_validate_address_and_port(char* string_to_parse, input_data_t* input_data) {
	char* separator_position_pointer = strchr(string_to_parse, ':');
	if (separator_position_pointer == NULL)
		fatal("invalid first argument");

	*separator_position_pointer = 0;
	++separator_position_pointer;

	input_data->connection_address = string_to_parse;
	input_data->connection_port = separator_position_pointer;
}

void parse_and_validate_http_tested_address(char* string_to_parse, input_data_t* input_data) {
	char* separator_position_pointer = strchr(string_to_parse, '/');
	if (separator_position_pointer == NULL)
		fatal("invalid third argument");

	++separator_position_pointer; // Second '/' in "http://".
	*separator_position_pointer = 0;
	++separator_position_pointer;
	input_data->host_name = separator_position_pointer;

	separator_position_pointer = strchr(string_to_parse, '/'); // Find the first '/' after host's name.
	if (separator_position_pointer == NULL)
		fatal("invalid third argument");

	*separator_position_pointer = 0;
	++separator_position_pointer;
	input_data->resource_path = separator_position_pointer;
}

// Puts data from parsed arguments under passed pointer to an input_data struct.
// Exits if there is an error while parsing or validating.
void parse_and_validate_arguments(int argc, char* argv[], input_data_t* input_data) {
	if (argc != 4)
		fatal("invalid argument count");

	parse_and_validate_address_and_port(argv[1], input_data);
	input_data->cookie_file_name = argv[2];
	parse_and_validate_http_tested_address(argv[3], input_data);
}


int main(int argc, char* argv[]) {
	// TODO Sparsuj i zwaliduj argumenty
	input_data_t input_data;
	parse_and_validate_arguments(argc, argv, &input_data);

	// TODO Przetworz plik tekstowy z ciasteczkami

	// TODO Przygotuj requesta http

	// TODO Polacz sie przez TCP z danym adresem/portem

	// TODO Przeslij requesta http do serwera

	// TODO Wczytaj wiersz statusu z reponse'a serwera (pierwsza linia)

	// TODO Jesli inny niz 200 OK, wypisz te pierwsza linie, zakoncz program

	// TODO Znajdz ciasteczka, wypisz je na stdout

	// TODO Znajdz dlugosc zasobu, wypisz ja na stdout

	// TODO Skrypt
}