#include "mrowka.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
mapa_t inicjuj_mape(int liczba_kolumn, int liczba_wierszy)
{
        mapa_t mapa=malloc(sizeof (*mapa));
	if(mapa==NULL)
	{
		printf("Nie udało się zaalokować pamięci na mape");
		return NULL;
	}
	mapa->liczba_kolumn=liczba_kolumn;
        mapa->liczba_wierszy=liczba_wierszy;

        mapa->kolory=malloc(liczba_wierszy*sizeof(char *));
	if(mapa->kolory==NULL)
	{
		free(mapa);
		printf("Nie udało się zaalokować pamięci na kolory");
		return NULL;
	}
        for(int i=0;i<mapa->liczba_kolumn;i++)
        {
                if((mapa->kolory[i]=malloc(liczba_kolumn*sizeof(char)))==NULL)
		{
			for (int j=i-1;j>=0;j--)
			{
				free(mapa->kolory[j]);
				
			}
			free(mapa->kolory);
			free(mapa);
			printf("Nie udało się zaalokować pamięci na wszystkie pola");
			return NULL;
		}

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
	int kolumny=mapa->liczba_kolumn;
	int wiersze=mapa->liczba_wierszy;
	int liczba_pol=floor(kolumny*wiersze*0.01*zapelnienie);
	int x,y;
	while(liczba_pol>0)
	{
		x=rand()%kolumny;
		y=rand()%wiersze;
		if(mapa->kolory[x][y]=='b')
		{
			mapa->kolory[x][y]='c';
			liczba_pol--;	
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
      	fclose(plik);	
	
}

void zwolnij_mape(mapa_t mapa)
{
        for(int i=0;i<mapa->liczba_wierszy;i++)
        {
                free(mapa->kolory[i]);
        }

        free(mapa->kolory);
	free(mapa);
}
