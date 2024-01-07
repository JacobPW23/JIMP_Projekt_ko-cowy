#include "mrowka.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>

mapa_t inicjuj_mape(int liczba_kolumn, int liczba_wierszy)
{
        mapa_t mapa=malloc(sizeof (*mapa));
	mapa->liczba_kolumn=liczba_kolumn;
        mapa->liczba_wierszy=liczba_wierszy;

        mapa->kolory=malloc(liczba_wierszy*sizeof(char *));
	if(mapa->kolory==NULL)
	{
		printf("Nie udało się zaalokować pamięci na mape");
		return NULL;
	}
        for(int i=0;i<mapa->liczba_kolumn;i++)
        {
                mapa->kolory[i]=malloc(liczba_kolumn*sizeof(char));
        }

	for(int i=0;i<mapa->liczba_wierszy;i++)
	{
		for(int j=0;j<mapa->liczba_kolumn;j++)
		{
			mapa->kolory[i][j]='b';
		}
	}

	return mapa;
}

void generuj_losowa_mape(mapa_t mapa, int zapelnienie)
{
        srand(time(NULL));
        for(int i=0;i<mapa->liczba_wierszy;i++)
        {
                for(int j=0;j<mapa->liczba_kolumn;j++)
                {
                        int random=(rand()%100)+1; //losowa liczba między 1 a 100
                        if(random<=zapelnienie) //szansa, że wylosowana liczba jest mniejsza od zapełnienie to zapelnienie %
                        {
                                mapa->kolory[i][j]='c';
                        }
                }
        }
}

void wczytaj_mape(char *nazwa_pliku, mapa_t mapa, mrowka_t mrowka)
{
	int nr_wiersza;
	int nr_kolumny;
	int kol_czarne;
	int wier_czarne;
	FILE *plik=fopen(nazwa_pliku, "r");
	if(plik==NULL)
	{
		printf("Nie udalo sie otworzyc pliku.\n");
		errno = -1;
		return;
	}
	fscanf(plik, "%d %d", &nr_wiersza, &nr_kolumny);//poczatkowe polozenie mrowki

	while(fscanf(plik, "%d %d", &wier_czarne, &kol_czarne)==2)
	{
		if((wier_czarne<mapa->liczba_wierszy && wier_czarne>=0) && kol_czarne<mapa->liczba_kolumn && kol_czarne>=0)
		{
			mapa->kolory[wier_czarne][kol_czarne]='c';
		}
	}	
      		
	
}

void zwolnij_mape(mapa_t mapa)
{
        for(int i=0;i<mapa->liczba_wierszy;i++)
        {
                free(mapa->kolory[i]);
        }

        free(mapa->kolory);
}
