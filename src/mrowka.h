#ifndef MROWKA
#define MROWKA
struct mapa;

typedef struct mrowka {
	int wiersz;
	int kolumna;
	char kolor_pola;
	char zwrot;
	int nr_iteracji;
} mrowka_t;
//struktura przechowujaca aktualny stan mrowki

void inicjuj(mrowka_t mrowka, int wiersz, int kolumna, char kolor_pola, char zwrot);
//ustawia poczatkowy stan mrowki

int przejscie(struct mapa mapa, mrowka_t stan);

//funkcja okreslajaca reguly przejscia i 
//odpowiadajaca za zmiane stanu mapy i mrowki
//zwraca 0 gdy nie ma bledow

void zwolnij_mrowke(mrowka_t *stan);
//zwalnia pamiec
#endif
