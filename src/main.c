#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "mrowka.h"
#include "mapa.h"
#include "wypisz.h"


int main(int argc, char **argv)
{
	int liczba_wierszy=10;
	int liczba_kolumn=10;
	int liczba_iteracji=5;
	char *przedrostek="prefix";
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
				exit(1);
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
	
	if(strcmp(nazwa_pliku, "domyslna")!=0)
	{
		wczytaj_mape(nazwa_pliku, mapa, mrowka);
	}

	else if(zapelnienie>=0)
	{
		generuj_losowa_mape(mapa, zapelnienie);
	}
	for(int i=1;i<=liczba_iteracji;i++)
	{
		char nr_iteracji[50];
		sprintf(nr_iteracji,"%d", i);
		char* nazwa = malloc(strlen(przedrostek)+strlen(nr_iteracji));
		
		strcpy(nazwa,przedrostek);
		strcat(nazwa,nr_iteracji);
		if(nazwa == NULL)
		{
			fprintf(stderr, "Nie udalo sie zaalokowac pamieci na nazwe\n");
			exit(2);
		}
		if(strcmp(przedrostek,"prefix")!=0){
			FILE *plik;
			if((plik=fopen(nazwa, "w"))== NULL)
			{
				free(nazwa);
				fprintf(stderr, "Nie udalo sie zaalokowac pamieci na plik wyjsciowyi\n");
				exit(3);
			} 
			else{
				wypisz(mapa, mrowka, plik);
				fclose(plik);
			}
		}
		if(przejscie(mapa, mrowka)==1)
		{
			fprintf(stderr, "Wyjscie za mape na %d iteracji\n", i);
			exit(4);
		}
		free(nazwa);
	}
	if(strcmp(przedrostek,"prefix")==0)
		wypisz(mapa, mrowka, stdout);
	zwolnij_mape(mapa);
	zwolnij_mrowke(mrowka);	
	return 0;
}
