default: bin/main.out

CXXFLAGS=-O3 -g -Wall -Wextra

bin/main.out: bin/main.o
	g++ $< -o $@ $(CXXFLAGS)

bin/%.o: src/%.cpp
	g++ $< -c -o $@ $(CXXFLAGS)
	
