#include <stdio.h>
#include "mapa.h"
#include "mrowka.h"

void wypisz(FILE *wypisz, mapa_t mapa, mrowka_t mrowka)
{
	for(int i=0;i<mapa->liczba_wierszy;i++)
	{
		for(int j=0;mapa->liczba_kolumn;j++)
		{
			if(mapa->kolory[i][j]=='b')
			{
				fprintf(wypisz, "%d %d \n", i, j);
			}
		}
	}
}
