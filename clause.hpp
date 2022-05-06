#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "case.hpp"
#include "variable.hpp"

using std::string;
using std::vector;
using std::cout;
using std::to_string;

enum class forme {
	FNC,
	FND,
};
template<nullptr_t>
class Clause_ final {
	public:
	Clause_(forme _type = forme::FNC) : type(_type) { }

	void AfficherClause();
	string GetDimacs();

	size_t GetSize() const;

	forme type;
	vector<Variable> vars;
};

template<nullptr_t T>
void Clause_<T>::AfficherClause() {
	unsigned long index = 0;
	for (Variable v : vars) {
		if (v.GetNeg()) {
			cout << "-";
		}
		switch (v.GetType()) {
			case varType::COCHEE:
				cout << "C";
				break;
			case varType::MENTEUR:
				cout << "M";
				break;
		}
		cout << v.GetIndex();
		if (index < vars.size() - 1) {
			switch (type) {
				case forme::FNC:
					cout << " ou ";
					break;
				case forme::FND:
					cout << " et ";
					break;
			}
		}

		index++;
	}
}

template<nullptr_t T>
string Clause_<T>::GetDimacs() {
	string output;
	for (Variable v : vars) {
		if (v.GetNeg()) {
			output += "-";
		}
		output += to_string(v.GetIndex() + 1) + " ";
	}
	return output + "0";
}

template<nullptr_t T>
size_t Clause_<T>::GetSize() const { return vars.size(); }

using Clause = Clause_<nullptr>;