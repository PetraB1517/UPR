CC=gcc
CFLAGS=-I.
DEPS = logika.h output.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

2048: main.c logika.o output.o
	$(CC) -o 2048 main.c logika.c output.c

2048sdl: main_grafika.c logika.o grafika.o
	$(CC) -lSDL2 -lSDL2_ttf -o 2048sdl main_grafika.c logika.o grafika.o

all: