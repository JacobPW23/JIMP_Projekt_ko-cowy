CC=gcc
CFLAGS= -Wall -g
TARGET = bin/mrowka

OBJ = src/main.o src/mapa.o src/mrowka.o src/wypisz.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

mrowka.o: src/mrowka.c src/mrowka.h src/struktury.h
	$(CC) $(CFLAGS) -c src/mrowka.c -o src/mrowka.o


mapa.o: src/mapa.c src/mapa.h src/struktury.h
	$(CC) $(CFLAGS) -c src/mapa.c -o src/mapa.o

wypisz.o: src/mapa.h src/mrowka.h
	$(CC) $(CFLAGS) -c src/wypisz.c - o src/wypisz.o

main.o: src/main.c src/mapa.h src/mrowka.h src/wypisz.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

clean:
	rm -f $(OBJ) $(TARGET)

