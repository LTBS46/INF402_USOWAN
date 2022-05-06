CC=g++
FLAGS=-g -Wall -Wextra -O3 -std=c++17

all: main

main: main.o case.o variable.o grille.o parser.o clause.o formule.o region.o sat.o lut.o
	$(CC) $(FLAGS) -o main $^


main.o: main.cpp grille.hpp parser.hpp
	$(CC) $(FLAGS) -c main.cpp

case.o: case.cpp case.hpp variable.hpp
	$(CC) $(FLAGS) -c case.cpp

variable.o: variable.cpp variable.hpp
	$(CC) $(FLAGS) -c variable.cpp

grille.o: grille.cpp grille.hpp case.hpp region.hpp sat.hpp lut.hpp
	$(CC) $(FLAGS) -c grille.cpp

parser.o: parser.cpp parser.hpp case.hpp
	$(CC) $(FLAGS) -c parser.cpp

clause.o: clause.cpp clause.hpp case.hpp variable.hpp
	$(CC) $(FLAGS) -c clause.cpp

formule.o: formule.cpp formule.hpp clause.hpp
	$(CC) $(FLAGS) -c formule.cpp

region.o: region.cpp region.hpp case.hpp formule.hpp clause.hpp lut.hpp
	$(CC) $(FLAGS) -c region.cpp

sat.o: sat.cpp sat.hpp lut.hpp
	$(CC) $(FLAGS) -c sat.cpp

lut.o: lut.cpp lut.hpp
	$(CC) $(FLAGS) -c lut.cpp

clean:
	rm -f *.o main
