#pragma once

#include <fstream>
#include <iostream>
#include <list>

#include "case.hpp"

using std::list;
using std::string;

class Parser final {
	public:
	Parser(string filePath);

	constexpr int GetH() const noexcept { return h; }
	constexpr int GetL() const noexcept { return l; }
	constexpr const list<Case>& GetNumbers() { return numbers; }

	list<list<int>> regions;

	private:
	int h, l;
	list<Case> numbers;
};