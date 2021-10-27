all: main

LIBS := -lSDL2 -lSDL2_image
CFLAGS := -Wall
CC := g++

main: main.o Game.o Texture.o Entity.o Player.o
	$(CC) $(CFLAGS) main.o Game.o Entity.o Texture.o Player.o -o main $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Game.o: Game.cpp Game.h
	$(CC) $(CFLAGS) -c Game.cpp

Texture.o: Texture.cpp Texture.h
	$(CC) $(CFLAGS) -c Texture.cpp

Entity.o: Entity.cpp Entity.h
	$(CC) $(CFLAGS) -c Entity.cpp

Player.o: Player.cpp Player.h
	$(CC) $(CFLAGS) -c Player.cpp

clean:
	rm -f *.o main

