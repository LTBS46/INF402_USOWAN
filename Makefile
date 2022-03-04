default: bin/main.out

#

bin/main.out: bin/main.o bin/Grid.o
	g++ $^ -o $@

bin/main.o: src/main.cpp src/common.hpp src/Grid.hpp src/BaseGrid.hpp
	g++ $< -c -o $@ -O3 -g -Wall -Wextra
	
bin/Grid.o: src/Grid.cpp src/common.hpp src/Grid.hpp src/BaseGrid.hpp
	g++ $< -c -o $@ -O3 -g -Wall -Wextra