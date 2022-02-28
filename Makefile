default: bin/main.out

bin/main.out: bin/main.o
	g++ $< -o $@

bin/%.o: src/%.cpp
	g++ $< -c -o $@
