#pragma once
#include <iostream>
#include "variable.hpp"

enum class caseType {
	BW_CASE,
	NUM_CASE,
};

using std::cout;
using std::nullptr_t;

template<nullptr_t>
class Case_ final {
	public:
	constexpr Case_(int _x, int _y, caseType _type, int _index, int _n = -1)
		: x(_x),
		y(_y),
		n(_n),
		index(_index),
		type(_type),
		var(Variable(index)) {
		switch (type) {
			case caseType::BW_CASE:
				var.SetType(varType::COCHEE);
				break;
			case caseType::NUM_CASE:
				var.SetType(varType::MENTEUR);
				break;
		}
	}
	constexpr Case_(const Case_& c1) = default;
	bool operator==(const Case_& c1) {
		cout << "Testing case equality\n";
		bool isEqual = (x == c1.x) && (y == c1.y) && (n == c1.n) &&
			(index == c1.index) && (type == c1.type) && (var == c1.var);
		return isEqual;
	}

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

	constexpr void SetIndex(int _index) { var.SetIndex(index = _index); }
	constexpr void SetType(caseType _type) {
		type = _type;

		switch (type) {
			case caseType::BW_CASE:
				var.SetType(varType::COCHEE);
				break;
			case caseType::NUM_CASE:
				var.SetType(varType::MENTEUR);
				break;
		}
	}

	constexpr void SetN(int _n) { n = _n; }
};

using Case = Case_<nullptr>;