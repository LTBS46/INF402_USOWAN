#pragma once

#include "common.hpp"

class Grid {
    protected:

    unsigned l, h;
    signed char* cells;
    bool* vwall;
    bool* hwall;

    public:
    Grid(unsigned __l, unsigned __h);
};