#include "Grid.hpp"

#include <stdexcept>

using std::out_of_range;

Grid::Grid(unsigned __l, unsigned __h) : BaseGrid<signed char>(__l, __h), vwall(new bool[(l - 1) * h]()), hwall(new bool[l * (h - 1)]()) {
    unsigned n = l, m = h;
    while (n-- > 0)while (m-- > 0)set_cell_value(n, m, -1);
}

Grid::~Grid(void) { delete [] vwall; delete [] hwall; }
