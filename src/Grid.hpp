#pragma once

#include "common.hpp"

class Grid final {
    protected:
    unsigned l, h;
    signed char* cells;
    bool* vwall;
    bool* hwall;

    public:

    //constructeur
    Grid(unsigned __l, unsigned __h);


    void set_cell_value(unsigned x, unsigned y, signed char v);


    signed char get_cell_value(unsigned x, unsigned y) const;
};