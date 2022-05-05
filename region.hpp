#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "case.hpp"
#include "formule.hpp"

using std::ostream;
using std::vector;

class Region final {
    public:
    Region();

    vector<Case> cases;
    Formule clausesRegion = Formule(FND);

    void CreerClauses();
    void RenderClauses(ostream& file);

    private:
    void ClauseUnMenteur();
};