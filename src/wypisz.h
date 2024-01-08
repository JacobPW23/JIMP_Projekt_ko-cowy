#ifndef WYPISZ_MAPE
#define WYPISZ_MAPE
#include "mapa.h"
#include "mrowka.h"
#include <stdio.h>
void wypisz(mapa_t mapa, mrowka_t mrowka);
char* generuj_oznaczenie_pola(int wiersz, int kolumna,mapa_t mapa,mrowka_t mrowka,FILE * strumien);
#endif
