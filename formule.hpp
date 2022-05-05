#ifndef FORMULE_H
#define FORMULE_H

#include <iostream>
#include <vector>
#include "clause.hpp"

using namespace std;

class Formule {

public:
	
	Formule(forme _type);
	
	forme type;
	vector<Clause> form;
	
	void AfficherFormule();
	void Convert();
};


#endif