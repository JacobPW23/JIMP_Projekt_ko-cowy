#include "mrowka.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <wchar.h>
#include <locale.h>
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
        for(int i=0;i<mapa->liczba_wierszy;i++)
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
	setlocale(LC_ALL, "C.UTF-8");
	FILE *plik=fopen(nazwa_pliku, "r");
	if(plik==NULL)
	{
		printf("Nie udalo sie otworzyc pliku.\n");
		errno = -1;
		return;
	
	}
	wchar_t linia[1024];
	int licznik_wierszy=0;
	int licznik_kolumn=0;
	wchar_t znak;
	fgetws(linia, sizeof(linia), plik);
	for (int j=0;licznik_wierszy<mapa->liczba_wierszy;j++)
	{
		fgetws(linia, sizeof(linia), plik);
		if(j%3==0)
		{
			licznik_kolumn=0;
			for(int i=2;(licznik_kolumn<mapa->liczba_kolumn);i+=5)
			{
					znak=linia[i];
					switch(znak)
                                	{
                                        	case L' ': //spacja
							  break;
						case L'█': mapa->kolory[licznik_wierszy][licznik_kolumn] = 'c'; 
							  break; //█

						case L'▲': mapa->kolory[licznik_wierszy][licznik_kolumn] = 'c'; 
							  mrowka->zwrot = 'N';
							  mrowka->wiersz=licznik_wierszy;
							  mrowka->kolumna=licznik_kolumn; 
							  break; //▲
						case L'▶': mapa->kolory[licznik_wierszy][licznik_kolumn] = 'c';
							  mrowka->zwrot='E';
							  mrowka->wiersz=licznik_wierszy;
                                                          mrowka->kolumna=licznik_kolumn;
							  break; //▶
						case L'▼': mapa->kolory[licznik_wierszy][licznik_kolumn] = 'c'; 
                                                          mrowka->zwrot='S';
							  mrowka->wiersz=licznik_wierszy;
                                                          mrowka->kolumna=licznik_kolumn;
                                                          break; //▼
						case L'◀': mapa->kolory[licznik_wierszy][licznik_kolumn] = 'c'; 
                                                          mrowka->zwrot='W';
							  mrowka->wiersz=licznik_wierszy;
                                                          mrowka->kolumna=licznik_kolumn;
                                                          break; //◀



						case L'△':
							  mapa->kolory[licznik_wierszy][licznik_kolumn] = 'b';
                                                          mrowka->zwrot = 'N';
							  mrowka->wiersz=licznik_wierszy;
                                                          mrowka->kolumna=licznik_kolumn;
							  break; //△
						case L'▷':
							  mapa->kolory[licznik_wierszy][licznik_kolumn] = 'b';
                                                          mrowka->zwrot = 'E';
							  mrowka->wiersz=licznik_wierszy;
                                                          mrowka->kolumna=licznik_kolumn;
							  break; //▷
						case L'▽':
							  mapa->kolory[licznik_wierszy][licznik_kolumn] = 'b';
                                                          mrowka->zwrot = 'S';mrowka->wiersz=licznik_wierszy;
                                                          mrowka->kolumna=licznik_kolumn;
							  break; //▽
						case L'◁':
							  mapa->kolory[licznik_wierszy][licznik_kolumn] = 'b';
                                                          mrowka->zwrot = 'W';
							  mrowka->wiersz=licznik_wierszy;
                                                          mrowka->kolumna=licznik_kolumn;
							  break; //◁

                                	}
				licznik_kolumn++;
			}
			licznik_wierszy++;
		}
	}
	printf("Wczytano mape\n");
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
