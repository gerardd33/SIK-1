#include "argument_parser.h"


int main(int argc, char* argv[]) {
	// TODO Sparsuj i zwaliduj argumenty
	input_data_t input_data;
	parse_and_validate_arguments(argc, argv, &input_data);

	printf("Arguments parsed correctly");

	// TODO Polacz sie przez TCP z danym adresem/portem

	// TODO Przygotuj requesta http

	// TODO Wyslij ciasteczka

	// TODO Przeslij requesta http do serwera

	// TODO Wczytaj wiersz statusu z reponse'a serwera (pierwsza linia)

	// TODO Jesli inny niz 200 OK, wypisz te pierwsza linie, zakoncz program

	// TODO Znajdz ciasteczka, wypisz je na stdout

	// TODO Znajdz dlugosc zasobu, wypisz ja na stdout

	// TODO Skrypt
}