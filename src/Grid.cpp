#include "Grid.hpp"


Grid::Grid(unsigned __l, unsigned __h) : l(__l), h(__h), cells(new signed char[l * h]), vwall(new bool[(l - 1) * h]), hwall(new bool[l * (h - 1)]) {
    unsigned long k = l;
    for (k *= h;k-- > 0;)cells[k] = -1;
}