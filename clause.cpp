#include "clause.hpp"

using namespace std;

Clause::Clause(forme _type) {
	type =_type;
}

void Clause::AfficherClause() {
	int index=0;
	for (Variable v : vars) {
		if (v.GetNeg()) {
			cout << "-";
		}
		switch(v.GetType()) {
			case COCHEE:
				cout << "C";
				break;
			case MENTEUR:
				cout << "M";
				break;
		}
		cout << v.GetIndex();
		if (index < vars.size()-1) {
			switch(v.GetType()) {
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

int Clause::GetSize() {
	return vars.size();
}