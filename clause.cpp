#include "clause.hpp"

using std::cout;
using std::to_string;

Clause::Clause(forme _type) : type(_type) { }

void Clause::AfficherClause() {
	unsigned long index = 0;
	for (Variable v : vars) {
		if (v.GetNeg()) {
			cout << "-";
		}
		switch (v.GetType()) {
			case COCHEE:
				cout << "C";
				break;
			case MENTEUR:
				cout << "M";
				break;
		}
		cout << v.GetIndex();
		if (index < vars.size() - 1) {
			switch (v.GetType()) {
				case FNC:
					cout << " ou ";
					break;
				case FND:
					cout << " et ";
					break;
			}
		}

		index++;
	}
}

string Clause::GetDimacs() {
	string output;
	for (Variable v : vars) {
		if (v.GetNeg()) {
			output += "-";
		}
		output += to_string(v.GetIndex() + 1);
		output += " ";
	}
	output += "0";

	return output;
}

size_t Clause::GetSize() const {
	return vars.size();
}