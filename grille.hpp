#ifndef GRILLE_H
#define GRILLE_H


#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include "case.hpp"
#include "parser.hpp"
#include "region.hpp"
#include "sat.hpp"

using namespace std;

class Grille {
public:
	
	Grille(Parser parser);
	
	int GetH();
	int GetL();
	Case GetCase(int x, int y);

	
	void AfficherGrille();
		
		
private:
	int h;
	int l;
	
	vector<vector<Case>> cases;
	vector<Region> regions;
	
};





#endif