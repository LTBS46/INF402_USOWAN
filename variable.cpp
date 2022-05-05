#include "variable.hpp"


Variable::Variable(int i) {
	type = COCHEE;
	neg = false;
	index = i;
}

Variable::Variable(const Variable &v1) {
	type = v1.type;
	neg = v1.neg;
	index = v1.index;
}

bool Variable::operator==(const Variable &v1) {
	return (type == v1.type) && (index == v1.index) && (neg == v1.neg);
}

int Variable::GetIndex() {
	return index;
}

varType Variable::GetType() {
	return type;
}

bool Variable::GetNeg() {
	return neg;
}

void Variable::SetIndex(int _index) {
	index = _index;
}

void Variable::SetType(varType _type) {
	type = _type;
}

void Variable::SetNeg(bool _neg) {
	neg = _neg;
}