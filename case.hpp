#pragma once

#include "variable.hpp"


enum caseType {
	BW_CASE,
	NUM_CASE,
};


class Case final {

	public:

	constexpr Case(int _x, int _y, caseType _type, int _index, int _n = -1) : x(_x), y(_y), n(_n), index(_index), type(_type), var(Variable(index)) {
		switch (type) {
			case BW_CASE:
				var.SetType(COCHEE);
				break;
			case NUM_CASE:
				var.SetType(MENTEUR);
				break;
		}
	}
	constexpr Case(const Case& c1) = default;
	bool operator==(const Case& c1);

	private:
	int x;
	int y;
	int n;
	int index;

	caseType type;


	public:
	Variable var;


	constexpr int GetX(void) const noexcept { return x; }
	constexpr int GetY(void) const noexcept { return y; }
	constexpr int GetN(void) const noexcept { return n; }
	constexpr int GetIndex(void) const noexcept { return index; }
	constexpr caseType GetType() const noexcept { return type; }

	constexpr void SetIndex(int _index) {
		var.SetIndex(index = _index);
	}
	constexpr void SetType(caseType _type) {
		type = _type;

		switch (type) {
			case BW_CASE:
				var.SetType(COCHEE);
				break;
			case NUM_CASE:
				var.SetType(MENTEUR);
				break;
		}
	}
	
	constexpr void SetN(int _n) {
		n = _n;
	}
};
