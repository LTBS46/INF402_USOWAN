#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;

// Look-Up Table class for solved grid/case type
class LUT {

public:

    LUT(int h, int l);

    bool LookUp(int x, int y);
    bool LookUpIndex(int i);

    void Set(int x, int y, bool c);
    void SetIndex(int i, bool c);

    void AfficherLUT();

    int GetAvailableCaseCount(int i);
    vector<int> GetAvailableCaseIndex(int i);
    vector<vector<int>> GetCombinationNonMenteur(int i, int n);

    int h;
    int l;

private:

    vector<vector<bool>> table;

};
