#include "mrowka.h"
#include "mapa.h"
#include <stdlib.h>
mrowka_t inicjuj(int wiersz, int kolumna, char kolor_pola, char zwrot)
{
	mrowka_t mrowka=malloc(sizeof *mrowka);
	mrowka->wiersz=wiersz;
	mrowka->kolumna=kolumna;
	mrowka->kolor_pola=kolor_pola;
	mrowka->zwrot=zwrot;
	mrowka->nr_iteracji=0;
	return mrowka;
}
int przejscie(mapa_t mapa,mrowka_t stan)
{
int* nr_kol=&(stan->kolumna);
int* nr_wier=&(stan->wiersz);
int wierszy_na_mapie=mapa->liczba_wierszy;
int kolumn_na_mapie=mapa->liczba_kolumn;
char zwrot=stan->zwrot;
char* obecne_pole_na_mapie=&(mapa->kolory[stan->wiersz][stan->kolumna]);
if(*obecne_pole_na_mapie=='b')
{
	switch(zwrot)
	{


		case 'N': stan->zwrot='E';*obecne_pole_na_mapie='c';if(*nr_kol==wierszy_na_mapie-1)  return 1; else *nr_kol++; break;
		case 'E': stan->zwrot='S';*obecne_pole_na_mapie='c';if(*nr_wier==wierszy_na_mapie-1) return 1; else *nr_wier++; break;
		case 'S': stan->zwrot='W';*obecne_pole_na_mapie='c';if(*nr_kol==0) return 1; else *nr_kol--;break;
		case 'W': stan->zwrot='N';*obecne_pole_na_mapie='c';if(*nr_wier==0) return 1 ;else*nr_wier--;break;

 	} 

}
if(*obecne_pole_na_mapie=='c')
{
       switch(zwrot)
       {


	       case 'N': stan->zwrot='W';*obecne_pole_na_mapie='b';if(*nr_kol==0)  return 1; else *nr_kol--;break;
	        case 'E': stan->zwrot='N';*obecne_pole_na_mapie='b';if(*nr_wier==0) return 1; else *nr_wier--;break;
		case 'S': stan->zwrot='E';*obecne_pole_na_mapie='b';if(*nr_kol==kolumn_na_mapie-1) return 1; else *nr_kol++; break;
		case 'W': stan->zwrot='S';*obecne_pole_na_mapie='b';if(*nr_wier==wierszy_na_mapie-1) return 1; else *nr_wier++; break;

        }
}
return 0;
}

void zwolnij_mrowke(mrowka_t stan)
{
free(stan);

}
