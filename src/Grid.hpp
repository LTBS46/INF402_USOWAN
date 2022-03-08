#pragma once

#include "BaseGrid.hpp"
#include "common.hpp"

class Grid final {
    protected:
    BaseGrid<signed char> values;
    BaseGrid<signed char*> regions;
    BaseGrid<signed char> color; // =0 => N/A, >0 => 
    public:

    //constructeur
    Grid(unsigned __l, unsigned __h);
    virtual ~Grid(void);
};