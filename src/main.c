#include <stdio.h>
#include <unistd.h>
#include "mrowka.h"
#include "mapa.h"


int main(int argc, char **argv)
{
	int liczba_wierszy=10;
	int liczba_kolumn=10;
	int liczba_iteracji=5;
	char **przedrostek="file";
	char kierunek_mrowki='N';
	char **nazwa_pliku="domyslna";

	int opt;
	while((opt = getopt(argc, argv, "m:n:i:f:d:l:"))!=-1)
	{
		switch(opt)
		{
			case 'm':
				printf("argument m: %s\n", optarg);
				liczba_wierszy = optarg;
				break;
			case 'n':
				printf("argument n: %s\n", optarg);
				liczba_kolumn = optarg;
				break;
			case 'i':
				printf("argument i: %s\n", optarg);
				liczba_iteracji = optarg;
				break;
			case 'f':
				printf("argument f: %s\n", optarg);
				przedrostek = optarg;
				break;
			case 'd':
				printf("argument d: %s\n", optarg);
				kierunek_mrowki = optarg;
				break;
			case 'l':
				printf("argument l: %s\n", optarg);
				nazwa_pliku = optarg;
				break;
			case '?':
				printf("nieznana opcja\n");
				break;
		}
	}
	

	return 0;
}
