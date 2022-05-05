#include "parser.hpp"

using namespace std;

Parser::Parser(string filePath) {
	fstream file;
	
	file.open(filePath, ios::in);
	
	if(file.fail()) {
		cout << "Couldn't open file" << endl;
		exit(-2);
	}
	
	
	string hauteur;
	string largeur;
	
	file >> hauteur >> largeur;
	
	h = stoi(hauteur);
	l = stoi(largeur);
	
	string content;
	
	while(file >> content) {
		if (content == "n") {
			string x, y, n;
			file >> x >> y >> n;
			numbers.push_back(Case(stoi(x), stoi(y), NUM_CASE, 0, stoi(n)));
		} else if (content == "r") {
			list<int> region;
			
			file >> content;
			int end = stoi(content);
			
			for (int i = 0; i < end; i++) {
				file >> content;
				region.push_back(stoi(content));
			}
			
			regions.push_back(region);
		}
	}
	
	file.close();
}


int Parser::GetH() {
	return h;
}

int Parser::GetL() {
	return l;
}

list<Case> Parser::GetNumbers() {
	return numbers;
}