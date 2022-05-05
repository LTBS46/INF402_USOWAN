#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "case.hpp"
#include "variable.hpp"

using std::vector;
using std::string;

enum forme {
	FNC,
	FND,
};

class Clause final {

	public:

	Clause(forme _type = FNC);

	void AfficherClause();
	string GetDimacs();

	size_t GetSize() const;

	forme type;
	vector<Variable> vars;

};
