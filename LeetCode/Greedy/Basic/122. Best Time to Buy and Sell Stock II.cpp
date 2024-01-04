#include <vector>
#include <iostream>
#include <cassert>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            int profit = prices[i + 1] - prices[i];
            if (profit > 0) {
                res += profit;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums;
    nums = stringToIntVector("[7,1,5,3,6,4]");
    assert(Solution().maxProfit(nums) == 7);
    return 0;
}
