##### Team18 Makefile #####

CC = gcc
DEBUG = -DDEBUG -g
CFLAGS = -ansi -std=c99 -Wall -c
LFLAGS = -ansi -std=C99 -Wall
AR = ar rc
RANLIB = ranlib
SRC = ./src/

all: server client

# test: PUT STUFF HERE FOR DEBUG 
###### generate object files #######

#target to generate menu.o
$(SRC)menu.o: $(SRC)menu.h $(SRC)menu.c
	$(CC) $(CFLAGS) $(SRC)menu.c -g -o $(SRC)menu.o

$(SRC)menu_DEBUG.o: $(SRC)menu.h $(SRC)menu.c
	$(CC) $(CFLAGS) $(DEBUG) $(SRC)menu.c -g -o $(SRC)menu_DEBUG.o


#target to generate AI.o
$(SRC)AI.o: $(SRC)AI.h $(SRC)AI.c $(SRC)board.h
	$(CC) $(CFLAGS) $(SRC)AI.c -g -o $(SRC)AI.o

$(SRC)AI_DEBUG.o: $(SRC)AI.h $(SRC)AI.c $(SRC)board.h
	$(CC) $(CFLAGS) $(DEBUG) $(SRC)AI.c -g -o $(SRC)AI_DEBUG.o


#target to generate board.o
$(SRC)board.o: $(SRC)board.h $(SRC)board.c $(SRC)AI.h
	$(CC) $(CFLAGS) $(SRC)board.c -g -o $(SRC)board.o

$(SRC)board_DEBUG.o: $(SRC)board.h $(SRC)board.c $(SRC)AI.h
	$(CC) $(CFLAGS) $(DEBUG) $(SRC)board.c -o $(SRC)board_DEBUG.o


#target to generate game.o
$(SRC)game.o: $(SRC)game.h $(SRC)game.c $(SRC)board.h $(SRC)AI.h $(SRC)server.h
	$(CC) $(CFLAGS) $(SRC)game.c -g -o $(SRC)game.o

$(SRC)game_DEBUG.o: $(SRC)game.h $(SRC)game.c $(SRC)board.h $(SRC)AI.h $(SRC)server.h
	$(CC) $(CFLAGS) $(DEBUG) $(SRC)game.c -o $(SRC)game_DEBUG.o

#target to generate chess.o
$(SRC)chess.o: $(SRC)chess.c $(SRC)menu.h
	$(CC) $(CFLAGS) $(SRC)chess.c -g -o $(SRC)chess.o

# client.o file
$(SRC)client.o: $(SRC)client.c $(SRC)menu.o $(SRC)AI.o $(SRC)board.o $(SRC)game.o $(SRC)chess.o
	$(CC) $(CFLAGS) $(SRC)client.c -g -o $(SRC)client.o

# server.o file
$(SRC)server.o: $(SRC)server.c $(SRC)server.h $(SRC)chess.h
	$(CC) $(CFLAGS) $(SRC)server.c -g -o $(SRC)server.o

# DEBUG Chess
$(SRC)chess_DEBUG.o: $(SRC)chess.c $(SRC)menu.h
	$(CC) $(CFLAGS) $(DEBUG) -c $(SRC)chess.c -o $(SRC)chess_DEBUG.o

# EXECUTABLES

#target to generate QueensGambit
client: $(SRC)client.o $(SRC)menu.o $(SRC)AI.o $(SRC)board.o $(SRC)game.o $(SRC)chess.o 
	$(CC) $(LFLAGS) $(SRC)client.o $(SRC)chess.o $(SRC)menu.o $(SRC)AI.o $(SRC)board.o $(SRC)game.o -o ./bin/client

server: $(SRC)server.o $(SRC)menu.o $(SRC)AI.o $(SRC)board.o $(SRC)game.o
	$(CC) $(LFLAGS) $(SRC)server.o $(SRC)menu.o $(SRC)AI.o $(SRC)board.o $(SRC)game.o -o ./bin/server

#target to clean
clean:
	rm -f ./src/*.o 
	rm -f ./bin/chess
	rm -f ./bin/chess_DEBUG
