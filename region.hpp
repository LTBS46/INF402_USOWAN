#ifndef REGION_H
#define REGION_H

#include "case.hpp"
#include "formule.hpp"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Region {
public:
    Region();

    vector<Case> cases;
    Formule clausesRegion = Formule(FND);

    void CreerClauses();
    void RenderClauses(fstream& file);

private:
    void ClauseUnMenteur();

};



#endif