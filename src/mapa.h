#ifndef MAPA
#define MAPA
#include "struktury.h"

void inicjuj_mape(mapa_t mapa, int liczba_kolumn, int liczba_wierszy);
//zaalokowanie pamieci na mape, wczytanie liczby kolumn, wierszy

void generuj_losowa_mape(mapa_t mapa, int zapelnienie);
//zapelnia losowo mape w zapelnienie procentach

void wczytaj_mape(char *nazwa_pliku, mapa_t mapa, mrowka_t mrowka);
//zapelnia mape z pliku, ustawia stan poczatkowy mrowki wedlug pliku

void zwolnij_mape(mapa_t mapa);
//zwalnia pamiec mapy
#endif
