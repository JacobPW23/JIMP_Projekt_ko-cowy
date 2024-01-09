#include "mrowka.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <wchar.h>
#include <locale.h>

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
	fgetws(linia, sizeof(linia), plik);
	for (int j=0;licznik_wierszy<mapa->liczba_wierszy;j++)
	{
		fgetws(linia, sizeof(linia), plik);
		if(j%5==0)
		{
			licznik_kolumn=0;
			for(int i=5;(licznik_kolumn<mapa->liczba_kolumn);i+=11)
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
}

void zwolnij_mape(mapa_t mapa)
{
        for(int i=0;i<mapa->liczba_wierszy;i++)
        {
                free(mapa->kolory[i]);
        }

        free(mapa->kolory);
}
