#pragma once

#include "case.hpp"
#include "formule.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using std::vector;
using std::ostream;

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