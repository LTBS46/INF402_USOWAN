
#include "grille.hpp"
#include <utility>
using std::ofstream;
using std::ios;
using std::cout;
using std::move;

Grille::Grille(Parser parser) : h(parser.GetH()), l(parser.GetL()), cases() {
	cases.reserve(h);

	for (int k = 0; k < h; ++k) {
		vector<Case> ligne;
		ligne.reserve(l);
		for (int j = 0; j < l; ++j) {
			ligne.push_back(Case(j, k, BW_CASE, ((j * l) + k)));
		}
		cases.push_back(move(ligne));
	}

	for (Case num : parser.GetNumbers()) {
		num.SetIndex((num.GetY() * h) + num.GetX());
		cases.at(num.GetY()).at(num.GetX()) = num;
	}

	int regionI = 0;
	for (const list<int> & r : parser.regions) {
		Region new_region = Region();
		for (int i : r) {
			--i;
			int y = i / h;
			int x = i % h;
			if ((cases.at(y).at(x)).GetType() == NUM_CASE) {
				new_region.cases.push_back(cases.at(y).at(x));
			}
		}
		regionI++;

		regions.push_back(new_region);
	}
	{
		ofstream dimacs("dimacs_out");
		for (Region r : regions) {
			r.CreerClauses();
			r.RenderClauses(dimacs);
		}
	}
	// string sat_output = SAT::exec("varisat dimacs_out");
}

Case Grille::GetCase(int x, int y) {
	return cases.at(y).at(x);
}


void Grille::AfficherGrille() {
	for (vector<Case> col : cases) {
		for (Case c : col) {
			switch (c.GetType()) {
				case BW_CASE:
					cout << ".";
					break;
				case NUM_CASE:
					cout << c.GetN();
					break;
			}
			cout << " ";
		}
		cout << "\n";
	}
}