#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // std::iota
#include <functional>
#include "../prettyprint.h"

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        std::vector<int> result(mat.size());
        // [0, 1, 2, ..., mat.size() - 1]
        std::iota(result.begin(), result.end(), 0);
        // partial sort since we were only asked to pick the first k
        std::partial_sort(result.begin(), result.begin() + k, result.end(), 
                        // custom compare function
                        [&mat](const auto& a, const auto& b) {
                            // two pointers that point to the the first 0 position (civilian) for comparaison
                            const auto a_ones = std::distance(begin(mat[a]), 
                                                              std::upper_bound(begin(mat[a]), 
                                                                               end(mat[a]), 1, std::greater<int>()));
                            const auto b_ones = std::distance(begin(mat[b]), 
                                                              std::upper_bound(begin(mat[b]), 
                                                                               end(mat[b]), 1, std::greater<int>()));
                            // 1. if two row have the same value, pick the "first"
                            // 2. or pick the "second" if it is better
                            return (a_ones == b_ones && a < b) || (a_ones < b_ones);
                        });
        // we only interested in the first k
        result.resize(k);
        return result;
    }
};

int main() {
    auto s = Solution();
    std::vector<std::vector<int>> mat;
    int k;

    mat = {{1,1,0,0,0},
           {1,1,1,1,0},
           {1,0,0,0,0},
           {1,1,0,0,0},
           {1,1,1,1,1}};
    k = 3;
    std::cout << s.kWeakestRows(mat, k) << std::endl;
    return 0;
}