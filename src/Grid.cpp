#include "Grid.hpp"

using std::get;

Grid::Grid(unsigned __l, unsigned __h) : values(__l, __h), regions(), color(__l, __h) {
    auto s = values.get_size();
    unsigned n = get<0>(s), m;
    while (n-- > 0) {
        m = get<1>(s);
        while (m-- > 0)values.get_cell_value(n, m) = -1;
    }
}
