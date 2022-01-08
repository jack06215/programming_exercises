#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

const int MINN = numeric_limits<int>::min();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        vector<vector<int>> dp(2, vector<int>(len + 1, 0));
        // s0: sell or do nothing
        // s1: buy or do nothing
        dp[0][0] = MINN;
        dp[1][0] = 0;

        for (int i = 1; i <= len; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i - 1]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i - 1]);
        }

        cout << dp << endl;
        return max(dp[0][len], dp[1][len]);
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        vector<vector<int>> dp(2, vector<int>(len + 1, 0));
        // s0: sell or do nothing
        // s1: buy or do nothing
        dp[0][0] = MINN;
        dp[1][0] = 0;

        for (int i = 1; i <= len; i++) {
            dp[0][i] = max(dp[0][i - 1], -prices[i - 1]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i - 1]);
        }

        cout << dp << endl;
        return max(dp[0][len], dp[1][len]);
    }
};

int main() {
    vector<int> prices = stringToIntVector("[7,1,5,3,6,4]");
    cout << Solution2().maxProfit(prices) << endl;

    return 0;
}