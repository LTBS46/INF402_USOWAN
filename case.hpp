#ifndef CASE_H
#define CASE_H

#include "variable.hpp"
#include <iostream>

using namespace std;

enum caseType {
	BW_CASE,
	NUM_CASE,
};


class Case {
	
public:

	Case(int _x, int _y, caseType _type, int _index, int _n = -1);
	Case(const Case &c1);
	bool operator==(const Case &c1);

private:
	int x;
	int y;
	int n;
	int index;
	
	caseType type;
	

public:
	Variable var;


	int GetX();
	int GetY();
	int GetN();
	int GetIndex();
	caseType GetType();
	
	void SetIndex(int _index);
	void SetType(caseType _type);
	void SetN(int _n);
};

#endif // CASE_H
