#pragma once

#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "case.hpp"
#include "parser.hpp"
#include "region.hpp"
#include "sat.hpp"
#include "lut.hpp"

using std::nullptr_t;
using std::cout;

template<nullptr_t>
class Grille_ final {
	public:
	Grille_(Parser parser);

	constexpr int GetH() const noexcept { return h; }
	constexpr int GetL() const noexcept { return l; }
	Case GetCase(int x, int y);

	void AfficherGrille();

	private:
	int h;
	int l;

	vector<vector<Case>> cases;
	vector<Region> regions;
};

using std::cout;
using std::ios;
using std::move;
using std::ofstream;

template<nullptr_t T>
Grille_<T>::Grille_(Parser parser) : h(parser.GetH()), l(parser.GetL()), cases() {
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
template<nullptr_t T>
Case Grille_<T>::GetCase(int x, int y) { return cases[y][x]; }
template<nullptr_t T>
void Grille_<T>::AfficherGrille() {
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

using Grille = Grille_<nullptr>;