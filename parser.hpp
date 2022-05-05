#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <list>
#include <fstream>
#include "case.hpp"

using namespace std;

class Parser {
public:
	
	Parser(string filePath);
	
	int GetH();
	int GetL();
	list<Case> GetNumbers();

	list<list<int>> regions;

private:
	int h, l;
	list<Case> numbers;
	
};

#endif