#include "mapa.h"
#include "mrowka.h"
#include <locale.h>
#include <stdio.h>
char* generuj_oznaczenie_pola(int wiersz, int kolumna,mapa_t mapa,mrowka_t mrowka)
{
char* pole=&(mapa->kolory[wiersz][kolumna]);

if(mrowka->wiersz==wiersz && mrowka->kolumna==kolumna)
{
//mamy do czynienie z polem mrowki
if(*pole=='c')
{

 	switch(mrowka->zwrot)

 	{
		case 'N': return "▲";break;
		case 'E': return "►"; break;
		case 'S': return "▼"; break;
		case 'W': return "◄";break;

 	}
}	
else if(*pole=='b')
{

 	switch(mrowka->zwrot)

 	{
		case 'N': return "△";break;
		case 'E': return "▷"; break;
		case 'S': return "▽"; break;
		case 'W': return "◁";break;

 	}
}
}
else{
//mamy do czynienia ze zwykłym polem
if(*pole=='c')
	return "█";
else return " ";
}

}
void wypisz(mapa_t mapa, mrowka_t mrowka, FILE *plik)
{
char* avatar;
int liczba_kolumn=mapa->liczba_kolumn;
int liczba_wierszy=mapa->liczba_wierszy;

for(int i=0;i<liczba_wierszy;i++)
{
       for(int j=0;j<liczba_kolumn;j++)
       {
               fprintf(plik,"┌─────────┐");

       }
       fprintf(plik, "\n");
       for(int k=0;k<3;k++){
	        for(int j=0;j<liczba_kolumn;j++)
	        {
	              if(k==1){
			avatar=generuj_oznaczenie_pola(i,j,mapa,mrowka);
		      	fprintf(plik, "│    %s    │", avatar);
		      }


		      else	fprintf(plik,"│         │");
	        }
        fprintf(plik, "\n");
        }
        for(int j=0;j<liczba_kolumn;j++)
        {
              fprintf(plik, "└─────────┘");
        }
        fprintf(plik, "\n");





}
	fprintf(plik,"\n\n");
}
