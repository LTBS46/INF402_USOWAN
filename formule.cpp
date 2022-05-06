#include "formule.hpp"

using std::cout;

Formule::Formule(forme _type) : type(_type) { }

void Formule::AfficherFormule() {
	cout << "(";
	unsigned long index = 0;
	for (Clause c : form) {
		c.AfficherClause();

		if (index < form.size() - 1) {
			switch (type) {
				case forme::FNC:
					cout << ") et (";
					break;
				case forme::FND:
					cout << ") ou (";
					break;
			}
		} else {
			cout << ")";
		}

		index++;
	}

	cout << "\n";
}

void Formule::Convert() {  // TODO: compléter IF
	// Calculer le nombre final N de clauses (sans supprimer les tautologies)
	// Creer une vecteur de N clauses vides
	// Remplir les clauses vides
	// [Option] supprimer les tautologies

	// Cas FND
	int N = 1;
	int S = 0;


	for (Clause& c : form) {
		auto ___gs = c.GetSize();
		S += ___gs;
		N *= ___gs;
	}

	vector<Clause> fnc(N, Clause(forme::FNC));

	int offset = N;

	// Pour  toute clause de fnc
	// pour chaque clause de fnd
	// push l'element correspondant dans fnc

	vector<int> indices_to_destroy;

	for (auto& elem : form) {
		auto ___gs = elem.GetSize();
		offset /= ___gs;
		std::cout << "Creating N = " << N << " clauses" << std::endl;
		for (int i = 0; i < N; i++) {
			int index = (i / offset) % ___gs;
			Variable var = elem.vars[index];

			if (std::find(fnc[i].vars.begin(), fnc[i].vars.end(), var) == fnc[i].vars.end()) {
				fnc[i].vars.push_back(var);
			}

			Variable negVar = var;
			negVar.SetNeg(!negVar.GetNeg());

			if (std::find(fnc[i].vars.begin(), fnc[i].vars.end(), negVar) == fnc[i].vars.end()) {
				// std::cout << "added clause to destroy" << "\n";
				indices_to_destroy.push_back(i);
				continue;
			}

		}
	}


	if (type == forme::FND) {
		form = fnc;
		type = forme::FNC;
	} else if (type == forme::FNC) {
		form = fnc;
		type = forme::FND;
	}
}
