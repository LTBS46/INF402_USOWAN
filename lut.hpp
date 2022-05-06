#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;

template<class T>
vector<vector<T>> comb(T N, T K) {
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's

    vector<vector<T>> output;

    // print integers and permute bitmask
    do {
        vector<T> combo;
        for (T i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) combo.push_back(i);
        }
        output.push_back(combo);
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));

    return output;
}

// Look-Up Table class for solved grid/case type


template<class T> // on va tricher un peux pour l'optimisation
class _LUT {

    public:

    _LUT(int _h, int _l) : h(_h), l(_l) {
        for (int i = 0; i < _h; i++) {
            vector<bool> line;
            for (int j = 0; j < _l; j++) {
                line.push_back(false);
            }
            table.push_back(line);
        }
    }

    bool LookUp(size_t x, size_t y) {
        return table[y][x];
    }
    bool LookUpIndex(size_t i) {
        return table[i / l][i % l];
    }

    void Set(size_t x, size_t y, bool c) {
        table[y][x] = c;
    }
    void SetIndex(size_t i, bool c) {
        table[i / l][i % l] = c;
    }

    void AfficherLUT() {
        for (vector<bool> l : table) {
            for (bool b : l) {
                std::cout << " " << b;
            }
            std::cout << "\n";
        }
    }

    int GetAvailableCaseCount(size_t i) {
        int count = 0;
        size_t x = i % l;
        size_t y = i / l;
        if (x)
            if (!LookUp(x - 1, y)) count++;
        if (x + 1 <  l)
            if (!LookUp(x + 1, y)) count++;
        if (y) // vu que on a tout le temp toujour y >= 0 on peut avoir (y - 1) < 0 que si y == 0 
            if (!LookUp(x, y - 1)) count++;
        if (y + 1 < h)
            if (!LookUp(x, y + 1)) count++;
        return count;
    }

    vector<size_t> GetAvailableCaseIndex(int i) {
        vector<size_t> result;

        size_t x = i % l;
        size_t y = i / l;

        if (x) {
            if (!LookUp(x - 1, y)) result.push_back((y * l) + x - 1);
        }

        if (x + 1 < l) {
            if (!LookUp(x + 1, y)) result.push_back((y * l) + x + 1);
        }

        if (y) {
            if (!LookUp(x, y - 1)) result.push_back(((y - 1) * l) + x);
        }

        if (y + 1 <  h) {
            if (!LookUp(x, y + 1)) result.push_back(((y + 1) * l) + x);
        }

        return result;
    }
    vector<vector<int>> GetCombinationNonMenteur(int i, int n) {

        int a = GetAvailableCaseCount(i);
        vector<size_t> cases = GetAvailableCaseIndex(i);
        vector<vector<int>> abs_comb = comb(a, n);
        vector<vector<T>> output;

        for (vector<int> c : abs_comb) {
            vector<int> combo;
            for (int i : c) {
                combo.push_back(cases.at(i));
            }
            output.push_back(combo);
        }

        return output;

    }

    size_t h;
    size_t l;

    private:

    vector<vector<bool>> table;

};


using LUT = _LUT<int>;