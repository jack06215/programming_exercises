#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int maxProfit(std::vector<int> prices) {
        int buy = prices[0];
        int profit = numeric_limits<int>::min();
        for (int i = 0; i < prices.size(); i++) {
            profit = max(profit, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return profit;
    }
};
