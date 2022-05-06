#include "lut.hpp"

 


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
