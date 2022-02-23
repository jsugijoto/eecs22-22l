# PhotoLab_v2 Makefile
# NOTE: test target is just to make compiling test easier

FLAGS = -Wall -ansi -std=c99
CC = gcc
TOTAL = Photolab.o FileIO.o Advanced.o DIPs.o
TOTAL_D = Photolab_d.o FileIO.o Advanced.o DIPs.o 
LIB = -L. -lfilter -lm
DEBUG = -g -DDEBUG

all: createLib.a PhotoLab_v2 PhotoLabTest

clean:
	rm -f *.o
	rm -f PhotoLab_v2
	rm -f PhotoLabTest
	rm -f libfilter.a
	rm -f aging.ppm
	rm -f edge.ppm
	rm -f posterize.ppm
	rm -f negative.ppm
	rm -f noise.ppm
	rm -f sharpen.ppm

createLib.a: Advanced.o DIPs.o
	ar rc libfilter.a DIPs.o Advanced.o
	ranlib libfilter.a

test: PhotoLabTest run

run: 
	./PhotoLabTest

PhotoLabTest: $(TOTAL_D) 
	$(CC) $(FLAGS) $(DEBUG) $(TOTAL_D) $(LIB) -o PhotoLabTest

FileIO.o: FileIO.c FileIO.h Constants.h
	$(CC) $(FLAGS) -c FileIO.c -o FileIO.o

DIPs.o: DIPs.c DIPs.h Constants.h
	$(CC) $(FLAGS) -c DIPs.c -o DIPs.o

Photolab.o: PhotoLab_v2.c 
	$(CC) $(FLAGS) -c PhotoLab_v2.c -o Photolab.o

Photolab_d.o: PhotoLab_v2.c
	$(CC) $(FLAGS) $(DEBUG) -c PhotoLab_v2.c -o Photolab_d.o

Advanced.o: Advanced.c Advanced.h Constants.h
	$(CC) $(FLAGS) -c Advanced.c -o Advanced.o

PhotoLab_v2: $(TOTAL)
	$(CC) $(FLAGS) $(TOTAL) $(LIB) -o2 -o PhotoLab_v2

