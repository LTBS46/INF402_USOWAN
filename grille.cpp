
#include "grille.hpp"

using namespace std;

Grille::Grille(Parser parser) {
	h = parser.GetH();
	l = parser.GetL();
	
	for (int k = 0; k < h; k++) {
		vector<Case> ligne;
		for (int j = 0; j < l; j++) {
			ligne.push_back(Case(j, k, BW_CASE, (j*l + k)));
		}
		cases.push_back(ligne);
	}
	
	for (Case num : parser.GetNumbers()) {
		num.SetIndex((num.GetY()*h) + num.GetX());
		cases.at(num.GetY()).at(num.GetX()) = num;
	}

	int regionI = 0;
	for (list<int> r : parser.regions) {
		Region new_region = Region();
		for (int i : r) {
			i--;
			int y = i / h;
			int x = i % h;
			if ((cases.at(y).at(x)).GetType() == NUM_CASE) {
				new_region.cases.push_back(cases.at(y).at(x));
			}
		}
		regionI++;

		regions.push_back(new_region);
	}

	fstream dimacs;
	dimacs.open("dimacs_out", ios::out);
	

	for (Region r : regions) {
		r.CreerClauses();
		r.RenderClauses(dimacs);
	}

	dimacs.close();

	// string sat_output = SAT::exec("varisat dimacs_out");
}

Case Grille::GetCase(int x, int y) {
	return cases.at(y).at(x);
}

int Grille::GetH() {
	return h;
}

int Grille::GetL() {
	return l;
}

void Grille::AfficherGrille() {
	for (vector<Case> col : cases) {
		for (Case c : col) {
			switch(c.GetType()) {
				case BW_CASE:
					cout << ".";
					break;
				case NUM_CASE:
					cout << c.GetN();
					break;
			}
			cout << " ";
		}
		cout << endl;
	}
}