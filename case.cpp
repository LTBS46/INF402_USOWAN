#include  "case.hpp"


Case::Case(int _x, int _y, caseType _type, int _index, int _n) {
	x = _x;
	y = _y;
	type = _type;
	n = _n;
	index = _index;
	
	var = Variable(index);
	switch(type) {
		case BW_CASE:
			var.SetType(COCHEE);
			break;
		case NUM_CASE:
			var.SetType(MENTEUR);
			break;
	}

}

Case::Case(const Case &c1) {
	x = c1.x;
	y = c1.y;
	type = c1.type;
	n = c1.n;
	var = c1.var;
}

bool Case::operator==(const Case &c1) {
	cout << "Testing case equality" << endl;
	bool isEqual = (x == c1.x) && (y == c1.y) && (n == c1.n) && (index == c1.index) && (type == c1.type) && (var == c1.var);
	return isEqual;


}

int Case::GetX() {
	return x;
}

int Case::GetY() {
	return y;
}

int Case::GetN() {
	return n;
}

int Case::GetIndex() {
	return index;
}

caseType Case::GetType() {
	return type;
}

void Case::SetIndex(int _index) {
	index = _index;
	var.SetIndex(index);
}

void Case::SetType(caseType _type) {
	type = _type;
	
	switch(type) {
		case BW_CASE:
			var.SetType(COCHEE);
		case NUM_CASE:
			var.SetType(MENTEUR);
	}
}

void Case::SetN(int _n) {
	n = _n;
}
