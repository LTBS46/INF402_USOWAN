#pragma once

#include <stdexcept>
#include <utility>

using std::move;
using std::out_of_range;

// la class qui suit est un template donc TOUT est dans le header même les définition
template<class E>
class BaseGrid {
    protected:
    unsigned l, h;
    E* elements;

    public:
    BaseGrid(unsigned __l, unsigned __h) : l(__l), h(__h), elements(new E[l * h]) { }

    BaseGrid(const BaseGrid& b) : BaseGrid(b.l, b.h) { for (unsigned k = 0;k < (h * l);k++) elements[k] = b.elements[k]; }
    BaseGrid(BaseGrid&& b) : l(b.l), h(b.h), elements(b.elements) { b.elements = nullptr; }
    virtual BaseGrid& operator=(const BaseGrid& b) { return *this = move(BaseGrid(b)); }
    virtual BaseGrid& operator=(BaseGrid&& b) { l = b.l, h = b.h, elements = b.elements, b.elements = nullptr; return *this; }

    //pourquoi "virtual", parce que c'est mieux, et si vous voulez savoir : giyf
    virtual ~BaseGrid(void) { if(!is_empty())delete [] elements; }

    virtual bool is_empty(void) const { return elements == nullptr; }

    virtual const E& get_cell_value(unsigned x, unsigned y) const {
        if (x >= l || y >= h)throw out_of_range("bad cell index");
        return elements[x + l * h];
    }
    virtual E& get_cell_value(unsigned x, unsigned y) {
        if (x >= l || y >= h)throw out_of_range("bad cell index");
        return elements[x + l * h];
    }
};