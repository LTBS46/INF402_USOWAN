#include "grille.hpp"
#include "parser.hpp"
#include "sat.hpp"
#include "formule.hpp"

#include <iostream>


using namespace std;


int main(int argc, char **argv) {
	if(argc != 2) {
		cout << "Usage: <program> <file>" << endl;
		exit(-1);
	}
	
	Parser parser = Parser(argv[1]);
	
	Grille grille = Grille(parser);

	cout << "\nGrille:\n";

	grille.AfficherGrille();
	
	cout << "\n";
	
	return 0;
}
