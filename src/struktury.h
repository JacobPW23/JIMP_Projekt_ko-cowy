#ifndef STRUKTURY
#define STRUKTURY

typedef struct mrowka {
        int wiersz;
        int kolumna;
        char zwrot;
} *mrowka_t;
//struktura przechowujaca aktualny stan mrowki

typedef struct mapa {
        int liczba_kolumn;
        int liczba_wierszy;
        char **kolory;
} *mapa_t;
//struktura przechowujaca aktualny stan mapy

#endif
