default: bin/main

bin/main: bin/main.o
  g++ $< -o $@

bin/main.o: src/main.cpp
  g++ $< -c -o $@
