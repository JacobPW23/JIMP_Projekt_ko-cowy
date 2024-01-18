# Mrówka Langtona

## Opis
Program służy symulacji Mrówki Langtona. Wynik jest wypisywany do pliku testowego w formie graficznej. 

## Instalacja i Uruchomienie
Aby uruchomić program, wystarczy skompilować i zlinkować pliki według dołączonego pliku `Makefile`. Aby zbudować plik wykonywalny, wystarczy uruchomić skrypt `Makefile` komendą `make`.

## Cechy Programu
Można ustawić:
- Rozmiar mapy
- Początkowy kierunek mrówki
- Liczbę przejść mrówki
- Przedrostek pliku wynikowego

Poza tym można wygenerować losową mapę o zapełnieniu w podanej liczbie procentów oraz możliwe jest wczytanie mapy o formacie pliku wyjściowego programu.

## Opcje Uruchamiania
Program możemy uruchomić z kilkoma opcjami:
- `-h`                  : wyświetla opcje 
- `-m <ilość_wierszy>`  : ustawia liczbę wierszy mapy
- `-n <ilość kolumn>`   : ustawia liczbę kolumn mapy
- `-i <liczba_iteracji>`: określa ilość kroków mrówki
- `-d <N-S-W-E>`        : określa początkowy kierunek mrówki (N-góra, S-dół, W-lewo, E-prawo)
- `-f <nazwa>`          : określa przedrostek pliku wynikowego
- `-r <procent>`        : procentowe zapełnienie mapy
- `-l <plik>`           : wczytaj mapę z pliku

### Domyślne Wartości
W przypadku nie podania niezbędnych parametrów, przybierają one domyślne wartości:
- Liczba iteracji: 5
- Kierunek mrówki: N
- Liczba wierszy: 10
- Liczba kolumn: 10
- W przypadku nie podania przedrostka pliku, ostatni stan mapy zostaje wypisany na standardowe wyjście

## Przykłady Użycia Programu

### Domyślne Ustawienia
Mapa 10x10, kierunek w górę, 5 iteracji, wynik na wyjście standardowe
![Domyślne Ustawienia](https://github.com/JacobPW23/JIMP_Projekt_ko-cowy/assets/153267469/df0469b8-6f82-438e-8eea-e5026238410f)

### Zmiana Wielkości Mapy na 4x5
![Zmiana Wielkości Mapy](https://github.com/JacobPW23/JIMP_Projekt_ko-cowy/assets/153267469/3e0fcc28-6c36-458a-b3bd-0f426f0ff610)

### 10 Iteracji Mapy Wypełnionej w 50%, Wyniki Zapisywane w Pliku `randomn`, Gdzie n to Numer Iteracji
![Iteracja 1](https://github.com/JacobPW23/JIMP_Projekt_ko-cowy/assets/153267469/387b6c7e-61ae-47e5-ba5d-9867c666fc4e)
![Iteracja 2](https://github.com/JacobPW23/JIMP_Projekt_ko-cowy/assets/153267469/903685fd-ecca-4230-bd57-9110770497db)

### Przykład Działania dla Mapy 100x100 i 11000 Iteracji
![Mapa 100x100, 11000 Iteracji](https://github.com/JacobPW23/JIMP_Projekt_ko-cowy/assets/153267469/05867b3a-6e0d-4bb6-bc58-81ea986b07c5)

## Autorzy
Michał Zalewski i Jakub Próchnicki


