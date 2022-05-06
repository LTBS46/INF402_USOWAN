#include <iostream>

#include "formule.hpp"
#include "grille.hpp"
#include "parser.hpp"
#include "sat.hpp"

using std::cout;
using std::noboolalpha;

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Usage: <program> <file>\n";
		exit(-1);
	}
	cout << noboolalpha;
	Parser parser = Parser(argv[1]);

	Grille grille = Grille(parser);

	cout << "\nGrille:\n";

	grille.AfficherGrille();

	cout << "\n";

	return 0;
}