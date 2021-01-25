#include <vector>
#include <cstddef>
#include <algorithm>

// class Solution {
// public:
//     int maxProfit(std::vector<int> &prices) {
//         size_t size = prices.size();
//         std::vector<int> s0(size);
//         std::vector<int> s1(size);
//         s0[0] = -prices[0];
//         for (size_t i = 1; i < size; ++i) {
//             s0[i] = std::max(s0[i - 1], s1[i - 1] - prices[i]);
//             s1[i] = std::max(s1[i - 1], s0[i - 1] + prices[i]);
//         }

//         return std::max(0, s1[size - 1]);
//     }
// };

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        size_t size = prices.size();
        int s0 = -prices[0];
        int s1 = 0;
        for (size_t i = 1; i < size; ++i) {
            s0 = std::max(s0, s1 - prices[i]);
            s1 = std::max(s1, s0 + prices[i]);
        }
        return std::max(0, s1);
    }
};