#include "Grid.hpp"

#include <stdexcept>

using std::out_of_range;

Grid::Grid(unsigned __l, unsigned __h) : l(__l), h(__h), cells(new signed char[l * h]), vwall(new bool[(l - 1) * h]()), hwall(new bool[l * (h - 1)]()) {
    unsigned long k = l;
    for (k *= h;k-- > 0;)cells[k] = -1;
}

void Grid::set_cell_value(unsigned x, unsigned y, signed char v) {
    if (x >= l || y >= h)throw out_of_range("bad cell index");
    cells[x + l * h] = v;
}

signed char Grid::get_cell_value(unsigned x, unsigned y) const {
    if (x >= l || y >= h)throw out_of_range("bad cell index");
    return cells[x + l * h];    
}