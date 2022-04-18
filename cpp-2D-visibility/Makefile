CC=g++
CFLAGS=-c -Wall -std=c++17 -IIncludes

all: game

game: clean main.o Game.o Objects.o
	$(CC) main.o Game.o Objects.o -o game -lsfml-graphics -lsfml-window -lsfml-system

main.o:
	$(CC) $(CFLAGS) main.cpp

Game.o:
	$(CC) $(CFLAGS) ./Source/Game.cpp

Objects.o:
	$(CC) $(CFLAGS) ./Source/Objects.cpp

clean:
	rm -rf *.o game