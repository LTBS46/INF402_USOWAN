#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "case.hpp"
#include "formule.hpp"
#include "lut.hpp"

using std::ostream;
using std::vector;

class Region final {
    public:
    Region();

    vector<Case> cases;
    Formule clausesRegion = Formule(FND);

    void CreerClauses(LUT case_type_lut);
    void RenderClauses(ostream& file);

    private:
    void ClauseUnMenteur(); // Règle: Un seul menteur par région
    void ClauseConfigNonMenteur(LUT case_type_lut); // Règle: combinaisons possibles si la case ne ment pas
};