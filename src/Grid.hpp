#pragma once

#include "BaseGrid.hpp"
#include "common.hpp"

class Grid final : public BaseGrid<signed char> {
    protected:
    bool* vwall;
    bool* hwall;

    public:

    //constructeur
    Grid(unsigned __l, unsigned __h);
    virtual ~Grid(void);
};