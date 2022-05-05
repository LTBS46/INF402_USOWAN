#include <iostream>

#include "case.hpp"

using std::cout;

bool Case::operator==(const Case& c1) {
	cout << "Testing case equality\n";
	bool isEqual = (x == c1.x) && (y == c1.y) && (n == c1.n) &&
		(index == c1.index) && (type == c1.type) && (var == c1.var);
	return isEqual;
}
