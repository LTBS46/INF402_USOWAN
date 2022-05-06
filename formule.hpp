#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "clause.hpp"

using std::vector;

class Formule final {
	public:
	Formule(forme _type);

	forme type;
	vector<Clause> form;

	void AfficherFormule();
	void Convert();
};
