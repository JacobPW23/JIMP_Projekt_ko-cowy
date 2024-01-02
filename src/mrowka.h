#ifndef MROWKA
#define MROWKA
#include "struktury.h"

mrowka_t inicjuj(int wiersz, int kolumna, char kolor_pola, char zwrot);
//ustawia poczatkowy stan mrowki

int przejscie(mapa_t  mapa, mrowka_t stan);

//funkcja okreslajaca reguly przejscia i 
//odpowiadajaca za zmiane stanu mapy i mrowki
//zwraca 0 gdy nie ma bledow

void zwolnij_mrowke(mrowka_t stan);
//zwalnia pamiec
#endif
