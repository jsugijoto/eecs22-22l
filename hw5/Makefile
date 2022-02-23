# Makefile for TicTacWowWeeWow
# Name: Jonathan Sugijoto
# ID: 58535060 

# Design Names
DESIGN = TicTacWowWeeWow

CC = gcc
DEBUG = -DDEBUG -g
CFLAGS = -ansi -std=c99 -Wall -c
LFLAGS = -ansi -std=c99 -Wall
AR = ar rc
RANLIB = ranlib


all: TicTacWowWeeWow

# Object Files

Player.o: Player.h Player.c
	$(CC) $(CFLAGS) $(DEBUG) Player.c -o Player.o

Board.o: Board.h Board.c
	$(CC) $(CFLAGS) $(DEBUG) Board.c -o Board.o

AI.o: AI.h AI.c
	$(CC) $(CFLAGS) $(DEBUG) AI.c -o AI.o

TicTacWowWeeWow.o: TicTacWowWeeWow.c Player.h Board.h AI.h
	$(CC) $(CFLAGS) $(DEBUG) TicTacWowWeeWow.c -o TicTacWowWeeWow.o

# Generate LibAI.a
libAI.a: AI.o
	$(AR) libAI.a AI.o
	$(RANLIB) libAI.a

# Generate Executables

TicTacWowWeeWow: TicTacWowWeeWow.o Board.o Player.o libAI.a
	$(CC) $(LFLAGS) TicTacWowWeeWow.o Board.o Player.o -L. -lAI -o TicTacWowWeeWow

# Cleaning directory

clean: 
	rm -f TicTacWowWeeWow
	rm -f TicTacWowWeeWow.o
	rm -f Board.o
	rm -f AI.o
	rm -f Player.o
	rm -f libAI.a
