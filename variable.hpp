#ifndef VARIABLE_H
#define VARIABLE_H


enum varType {
	COCHEE,
	MENTEUR,
};


class Variable {

public:

	Variable(int i=-1);
	
	Variable(const Variable &v1);
	bool operator==(const Variable &v1);
	
	
private:

	varType type;
	int index;
	bool neg;

public:

	varType GetType();
	bool GetNeg();
	int GetIndex();

	void SetType(varType _type);
	void SetNeg(bool _neg);
	void SetIndex(int _index);

};




#endif