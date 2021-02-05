#include <vector>
#include <utility>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int s0 = -prices[0];
        int s1 = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            s0 = std::max(s0, -prices[i]);
            s1 = std::max(s1, prices[i] + s0);
        }
        return std::max(0, s1);
    }
};