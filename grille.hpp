#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "case.hpp"
#include "parser.hpp"
#include "region.hpp"
#include "sat.hpp"


class Grille final {
	public:

	Grille(Parser parser);

	constexpr int GetH() const noexcept {
		return h;
	}
	constexpr int GetL() const noexcept {
		return l;
	}
	Case GetCase(int x, int y);


	void AfficherGrille();


	private:
	int h;
	int l;

	vector<vector<Case>> cases;
	vector<Region> regions;

};