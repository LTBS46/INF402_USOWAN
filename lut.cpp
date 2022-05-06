#include "lut.hpp"

LUT::LUT(int _h, int _l) {
    h = _h;
    l = _l;
    for (int i=0; i<_h; i++) {
        vector<bool> line;
        for (int j=0; j<_l; j++) {
            line.push_back(false);
        }
        table.push_back(line);
    }
}

bool LUT::LookUp(int x, int y) {
    return table.at(y).at(x);
}

bool LUT::LookUpIndex(int i) {
    int x = i % l;
    int y = i / l;
    return table.at(y).at(x);
}

void LUT::Set(int x, int y, bool c) {
    table.at(y).at(x) = c;
}

void LUT::SetIndex(int i, bool c) {
    int x = i % l;
    int y = i / l;
    table.at(y).at(x) = c;
}

void LUT::AfficherLUT() {
    for (vector<bool> l : table) {
        for (bool b : l) {
            std::cout << " " << (b ? "1" : "0");
        }
        std::cout << "\n";
    }
}

int LUT::GetAvailableCaseCount(int i) {
    int count = 0;

    int x = i % l;
    int y = i / l;

    if (x-1 >= 0) {
        if (!LookUp(x-1, y)) count++;
    }

    if (x+1 < l) {
        if (!LookUp(x+1, y)) count++;
    }

    if (y-1 >= 0) {
        if (!LookUp(x, y-1)) count++;
    }

    if (y+1 < h) {
        if (!LookUp(x, y+1)) count++;
    }

    return count;
}

vector<int> LUT::GetAvailableCaseIndex(int i) {
    vector<int> result;

    int x = i % l;
    int y = i / l;

    if (x-1 >= 0) {
        if (!LookUp(x-1, y)) result.push_back((y*l)+x-1);
    }

    if (x+1 < l) {
        if (!LookUp(x+1, y)) result.push_back((y*l)+x+1);
    }

    if (y-1 >= 0) {
        if (!LookUp(x, y-1)) result.push_back(((y-1)*l)+x);
    }

    if (y+1 < h) {
        if (!LookUp(x, y+1)) result.push_back(((y+1)*l)+x);
    }

    return result;
}


vector<vector<int>> comb(int N, int K)
{
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
 
    vector<vector<int>> output;

    // print integers and permute bitmask
    do {
        vector<int> combo;
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) combo.push_back(i);
        }
        output.push_back(combo);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return output;
}


vector<vector<int>> LUT::GetCombinationNonMenteur(int i, int n) {

    int a = GetAvailableCaseCount(i);
    vector<int> cases = GetAvailableCaseIndex(i);
    vector<vector<int>> abs_comb = comb(a, n);

    vector<vector<int>> output;

    for (vector<int> c : abs_comb) {
        vector<int> combo;
        for (int i : c) {
            combo.push_back(cases.at(i));
        }
        output.push_back(combo);
    }

    return output;

}