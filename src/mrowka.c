#include "mrowka.h"
#include "mapa.h"
#include <stdlib.h>
#include <stdio.h>
mrowka_t inicjuj(int wiersz, int kolumna, char zwrot)
{
	mrowka_t mrowka=malloc(sizeof *mrowka);
	if(mrowka==NULL)
	{
		printf("Nie udalo sie zaalokowac pamieci na mrowke");
		return NULL;
	}
	mrowka->wiersz=wiersz;
	mrowka->kolumna=kolumna;
	mrowka->zwrot=zwrot;
	mrowka->nr_iteracji=0;
	return mrowka;
}
int przejscie(mapa_t mapa,mrowka_t mrowka)
{
int* nr_kol=&(mrowka->kolumna);
int* nr_wier=&(mrowka->wiersz);
int wierszy_na_mapie=mapa->liczba_wierszy;
int kolumn_na_mapie=mapa->liczba_kolumn;
char zwrot=mrowka->zwrot;
char* obecne_pole_na_mapie=&(mapa->kolory[mrowka->wiersz][mrowka->kolumna]);
if(*obecne_pole_na_mapie=='b')
{
	switch(zwrot)
	{


		case 'N': mrowka->zwrot='E';*obecne_pole_na_mapie='c';if(*nr_kol==kolumn_na_mapie-1)  return 1; else (*nr_kol)++; break;
		case 'E': mrowka->zwrot='S';*obecne_pole_na_mapie='c';if(*nr_wier==wierszy_na_mapie-1) return 1; else (*nr_wier)++; break;
		case 'S': mrowka->zwrot='W';*obecne_pole_na_mapie='c';if(*nr_kol==0) return 1; else (*nr_kol)--;break;
		case 'W': mrowka->zwrot='N';*obecne_pole_na_mapie='c';if(*nr_wier==0) return 1 ;else (*nr_wier)--;break;

 	} 

}
else if(*obecne_pole_na_mapie=='c')
{
       switch(zwrot)
       {


	        case 'N': mrowka->zwrot='W';*obecne_pole_na_mapie='b';if(*nr_kol==0)  return 1; else (*nr_kol)--;break;
	        case 'E': mrowka->zwrot='N';*obecne_pole_na_mapie='b';if(*nr_wier==0) return 1; else (*nr_wier)--;break;
		case 'S': mrowka->zwrot='E';*obecne_pole_na_mapie='b';if(*nr_kol==kolumn_na_mapie-1) return 1; else (*nr_kol)++; break;
		case 'W': mrowka->zwrot='S';*obecne_pole_na_mapie='b';if(*nr_wier==wierszy_na_mapie-1) return 1; else (*nr_wier)++; break;

        }
}
return 0;
}

void zwolnij_mrowke(mrowka_t mrowka)
{
free(mrowka);

}
