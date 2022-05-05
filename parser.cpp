#include "parser.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::ios;

Parser::Parser(string filePath) {
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
			numbers.push_back(Case(x, y, NUM_CASE, 0, n));
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