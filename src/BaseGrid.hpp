#pragma once

// la class qui suit est un template donc TOUT est dans le header même les définition
template<class E>
class BaseGrid {
    protected:
    E* elements;
    unsigned l, h;

    public:
    BaseGrid(unsigned __l, unsigned __h) : l(__l), h(__h), elements(new E[l * h]) { }

    //pourquoi "virtual", parce que c'est mieux, et si vous voulez savoir : giyf
    virtual ~BaseGrid(void) { delete [] elements; }

    void set_cell_value(unsigned x, unsigned y, signed char v) {
        if (x >= l || y >= h)throw out_of_range("bad cell index");
        elements[x + l * h] = v;
    }

    E get_cell_value(unsigned x, unsigned y) const {
        if (x >= l || y >= h)throw out_of_range("bad cell index");
        return elements[x + l * h];
    }
};