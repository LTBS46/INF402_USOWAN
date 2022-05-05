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
				case FNC:
					cout << ") et (";
					break;
				case FND:
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

void Formule::Convert() { // TODO: compléter IF
	// Calculer le nombre final N de clauses (sans supprimer les tautologies)
	// Creer une vecteur de N clauses vides
	// Remplir les clauses vides
	// [Option] supprimer les tautologies

	// Cas FND
	int N = 1;
	int S = 0;


	if (type == FND) {

		for (Clause& c : form) {
			S += c.GetSize();
			N *= c.GetSize();
		}


		vector<Clause> fnc(N, Clause(FNC));

		int offset = N;

		// Pour  toute clause de fnc
		// pour chaque clause de fnd
		// push l'element correspondant dans fnc

		for (unsigned long j = 0; j < form.size(); j++) {


			offset = offset / form.at(j).GetSize();

			for (int i = 0; i < N; i++) {
				// Formule de la variable correspondante dans la clause				
				int index = (i / offset) % form.at(j).GetSize();


				Variable var = form.at(j).vars.at(index);

				fnc.at(i).vars.push_back(var);



			}
		}

		form = fnc;
		type = FNC;

	}
}

