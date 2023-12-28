#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

vector<int> coins;
int amount;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        cout << dp << endl;
        for (const auto& coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
        cout << dp << endl;
        return dp[amount] > amount ? -1 : dp[amount];;
    }
};


int main(int argc, const char* argv[]) {
    coins = stringToIntVector("[1,2,5]"), amount = 11;
    cout << Solution().coinChange(coins, amount);

    return 0;
}
