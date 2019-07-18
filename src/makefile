CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -g3

biblioteca: argparser.o main.o pilha.o quicksort.o vector_generator.o
	$(CC) $(CFLAGS) -o biblioteca argparser.o main.o pilha.o quicksort.o vector_generator.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

argparser.o: argparser.cpp argparser.hpp
	$(CC) $(CFLAGS) -c argparser.cpp

pilha.o: pilha.cpp pilha.hpp
	$(CC) $(CFLAGS) -c pilha.cpp

quicksort.o: quicksort.hpp quicksort.cpp argparser.hpp argparser.cpp pilha.hpp pilha.cpp
	$(CC) $(CFLAGS) -c quicksort.cpp

vector_generator.o: vector_generator.cpp vector_generator.hpp
	$(CC) $(CFLAGS) -c vector_generator.cpp

clean:
	rm *.o
