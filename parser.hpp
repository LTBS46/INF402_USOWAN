#pragma once

#include <fstream>
#include <iostream>
#include <list>

#include "case.hpp"

using std::list;
using std::string;
using std::nullptr_t;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;


template<nullptr_t>
class Parser_ final {
	public:
	Parser_(string filePath);

	constexpr int GetH() const noexcept { return h; }
	constexpr int GetL() const noexcept { return l; }
	constexpr const list<Case>& GetNumbers() { return numbers; }

	list<list<int>> regions;

	private:
	int h, l;
	list<Case> numbers;
};

template<nullptr_t N>
Parser_<N>::Parser_(string filePath) {
	ifstream file(filePath);

	if (file.fail()) {
		cout << "Couldn't open file\n";  // peut-etre plutot cerr ?
		exit(-2);
	}

	file >> h >> l;

	string content;

	while (file >> content) {
		if (content == "n") {
			int x, y, n;
			file >> x >> y >> n;
			numbers.push_back(Case(x, y, caseType::NUM_CASE, 0, n));
		} else if (content == "r") {
			list<int> region;

			int end;
			file >> end;

			for (int i = 0; i < end; i++) {
				int val;
				file >> val;
				region.push_back(val);
			}

			regions.push_back(region);
		}
	}
}
using Parser = Parser_<nullptr>;