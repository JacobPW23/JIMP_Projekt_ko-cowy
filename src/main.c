#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include "mrowka.h"
#include "mapa.h"
#include "wypisz.h"


int main(int argc, char **argv)
{
	int liczba_wierszy=10;
	int liczba_kolumn=10;
	int liczba_iteracji=5;
	char *przedrostek="file";
	char kierunek_mrowki='N';
	char *nazwa_pliku="domyslna";
	int zapelnienie=-1;

	int opt;
	while((opt = getopt(argc, argv, "m:n:i:f:d:l:r:h"))!=-1)
	{
		switch(opt)
		{
			case 'm':
				//liczba wierszy
				liczba_wierszy = atoi(optarg);
				break;
			case 'n':
				//liczba kolumn
				liczba_kolumn = atoi(optarg);
				break;
			case 'i':
				//liczba iteracji
				liczba_iteracji = atoi(optarg);
				break;
			case 'f':
				//przedrostek pliku wynikowego
				przedrostek = optarg;
				break;
			case 'd':
				//kierunek mrowki
				kierunek_mrowki = optarg[0];
				break;
			case 'l':
				//zaladuj mapę
				nazwa_pliku = optarg;
				printf("Argument to %s\n", nazwa_pliku);
				break;
			case 'r':
				//generuj losową mapę
				zapelnienie = atoi(optarg);
				break;
			case 'h':
				printf("Opcje: \n");
				printf("-m : liczba wierszy mapy\n");
				printf("-n : liczba kolumn mapy\n");
			        printf("-i : liczba iteracji przejść\n");
				printf("-f : nazwa pliku wynikowego\n");
				printf("-d : początkowy kierunek mrówki N-północ E-wschód S-południe W-zachód\n");
				printf("-l : załaduj mapę z pliku\n");
				printf("-r : wygeneruj losową mapę zapełnioną w procentach\n");
				printf("-h : wyświetl pomoc\n");
				break;	
			case '?':
				printf("nieznana opcja\n");
				break;
		}
	}
	
	mapa_t mapa;
	mrowka_t mrowka;
	mapa=inicjuj_mape(liczba_wierszy, liczba_kolumn);
	mrowka=inicjuj(liczba_kolumn/2, liczba_wierszy/2, kierunek_mrowki);
	
	if((strcmp(nazwa_pliku, "domyslna"))!=0)
	{	
		wczytaj_mape(nazwa_pliku, mapa, mrowka);
	}

	if(zapelnienie>=0)
	{
		generuj_losowa_mape(mapa, zapelnienie);
	}

	for(int i=1;i<=liczba_iteracji;i++)
	{
		if(strcmp(przedrostek, "file")==0)
		{
			wypisz(mapa, mrowka, stdout);
		}
		else
		{
			char nr_iteracji[50];
			sprintf(nr_iteracji,"%d", i);
			char *nazwa = malloc(strlen(przedrostek)+strlen(nr_iteracji));
			if(nazwa == NULL)
			{
				perror("Nie udalo sie zaalokowac pamieci na nazwe");
				exit(1);
			}
			strcat(nazwa, przedrostek);
			strcat(nazwa, nr_iteracji);
			FILE *plik = fopen(nazwa, "w");
			if(plik == NULL)
			{
				perror("Nie udalo sie zaalokowac pamieci na plik wyjsciowy");
				exit(1);
			}

			wypisz(mapa, mrowka, plik);
		}
		przejscie(mapa, mrowka);
	}

	return 0;
}
