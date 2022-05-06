
#include <utility>

#include "grille.hpp"
using std::cout;
using std::ios;
using std::move;
using std::ofstream;

Grille::Grille(Parser parser) : h(parser.GetH()), l(parser.GetL()), cases() {
	cases.reserve(h);

	LUT case_type_lut = LUT(h, l);	// Look-Up table for case type (false: black and white, true: number)

	for (int k = 0; k < h; ++k) {
		vector<Case> ligne;
		ligne.reserve(l);
		for (int j = 0; j < l; ++j) {
			ligne.push_back(Case(j, k, caseType::BW_CASE, ((j * l) + k)));
		}
		cases.push_back(move(ligne));
	}

	for (Case num : parser.GetNumbers()) {
		num.SetIndex((num.GetY() * h) + num.GetX());
		cases[num.GetY()][num.GetX()] = num;
		case_type_lut.Set(num.GetX(), num.GetY(), true);
	}

	for (const list<int>& r : parser.regions) {
		Region new_region = Region();
		for (int i : r) {
			--i;
			int y = i / h;
			int x = i % h;
			if (cases[y][x].GetType() == caseType::NUM_CASE) {
				new_region.cases.push_back(cases[y][x]);
			}
		}

		regions.push_back(new_region);
	}
	{
		ofstream dimacs("dimacs_out");
		for (Region r : regions) {
			cout << "calling new region" << std::endl;
			r.CreerClauses(case_type_lut);
			r.RenderClauses(dimacs);
			cout << "region done" << std::endl;
		}
	}
	// string sat_output = SAT::exec("varisat dimacs_out");
	// cout << sat_output << "\n";
	// SAT::GetResult(sat_output, h, l);
	case_type_lut.AfficherLUT();
}

Case Grille::GetCase(int x, int y) { return cases[y][x]; }

void Grille::AfficherGrille() {
	for (vector<Case> col : cases) {
		for (Case c : col) {
			switch (c.GetType()) {
				case caseType::BW_CASE:
					cout << ".";
					break;
				case caseType::NUM_CASE:
					cout << c.GetN();
					break;
			}
			cout << " ";
		}
		cout << "\n";
	}
}
