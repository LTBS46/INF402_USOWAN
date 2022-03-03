default: bin/main.out

#

bin/main.out: bin/main.o bin/Grid.o
	g++ $^ -o $@

bin/%.o: src/%.cpp
	g++ $< -c -o $@ -O3 -g -Wall -Wextra
	
