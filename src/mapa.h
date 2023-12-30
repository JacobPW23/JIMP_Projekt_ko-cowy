#ifndef MAPA
#define MAPA
struct mrowka;

typedef struct mapa {
	int liczba_kolumn;
	int liczba_wierszy;
	char **kolory;
} mapa_t;
//struktura przechowujaca aktualny stan mapy

void inicjuj_mape(mapa_t mapa, int liczba_kolumn, int liczba_wierszy);
//zaalokowanie pamieci na mape, wczytanie liczby kolumn, wierszy

void generuj_losowa_mape(mapa_t mapa, int zapelnienie);
//zapelnia losowo mape w zapelnienie procentach

void wczytaj_mape(char *nazwa_pliku, mapa_t mapa, struct mrowka mrowka);
//zapelnia mape z pliku, ustawia stan poczatkowy mrowki wedlug pliku

void zwolnij_mape(mapa_t *mapa);
//zwalnia pamiec mapy
#endif
