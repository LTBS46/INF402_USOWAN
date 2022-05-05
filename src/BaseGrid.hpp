#pragma once

#include <stdexcept>
#include <utility>
#include <tuple>

using std::tuple;
using std::move;
using std::out_of_range;

// la class qui suit est un template donc TOUT est dans le header même les définition
template<class E>
class BaseGrid final {
    protected:
    unsigned l, h;
    E* elements;

    public:
    BaseGrid(unsigned __l, unsigned __h) : l(__l), h(__h), elements((l* h) == 0 ? new E[l * h]() : nullptr) { }
    BaseGrid(void) noexcept : BaseGrid(0, 0) { }
    BaseGrid(const BaseGrid& b) : BaseGrid(b.l, b.h) { for (unsigned k = 0;k < (h * l);k++) elements[k] = b.elements[k]; }
    BaseGrid(BaseGrid&& b) : l(b.l), h(b.h), elements(b.elements) { b.elements = nullptr; }
    BaseGrid& operator=(const BaseGrid& b) { return *this = move(BaseGrid(b)); }
    BaseGrid& operator=(BaseGrid&& b) { l = b.l, h = b.h, elements = b.elements, b.elements = nullptr; return *this; }

    tuple<unsigned, unsigned> get_size(void) const { return { l, h }; }

    ~BaseGrid(void) { if (!is_empty())delete [] elements; }

    bool is_empty(void) const { return elements == nullptr; }

    const E& get_cell_value(unsigned x, unsigned y) const {
        if (x >= l || y >= h)throw out_of_range("bad cell index");
        return elements[x + l * h];
    }

    E& get_cell_value(unsigned x, unsigned y) {
        if (x >= l || y >= h)throw out_of_range("bad cell index");
        return elements[x + l * h];
    }
};