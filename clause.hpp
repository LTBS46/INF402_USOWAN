#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "case.hpp"
#include "variable.hpp"

using std::string;
using std::vector;

enum class forme {
	FNC,
	FND,
};

class Clause final {
	public:
	Clause(forme _type = forme::FNC);

	void AfficherClause();
	string GetDimacs();

	size_t GetSize() const;

	forme type;
	vector<Variable> vars;
};
