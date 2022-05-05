#ifndef CLAUSE_H
#define CLAUSE_H

#include <iostream>
#include <vector>
#include <string>
#include "case.hpp"
#include "variable.hpp"

using namespace std;

enum forme {
	FNC,
	FND,
};

class Clause {

public:

	Clause(forme _type = FNC);
	
	void AfficherClause();
	string GetDimacs();
	
	int GetSize();
	
	forme type;
	vector<Variable> vars;
	
};


#endif