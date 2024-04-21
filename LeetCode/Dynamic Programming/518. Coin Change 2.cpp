#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"


/* Initialization 
    - for $0 how many ways can we pay using coin $0 -> 1 way
    - for $1 how many ways can we pay using coin $0 -> 0 way
    - for $0 how many ways can we pay using coin $2 -> 1 way because we can just pay $0
    - same thing goes for $5
    Here's what the matrix looks like, row is the coin[i], column is the amount

                0  1  2  3  4  5     
            0    1  0  0  0  0  0

            2    1                     <------DP MATRIX

            5    1

    Now, consider the next paying amount using $2
    - how many ways can we pay $1 using coin $2 -> 0 way because we can not pay $2.
    - how many ways can we pay $2 using coin $2 -> 1 way because we can just use a $2.
    - how many ways can we pay $3 using coin $2 -> 0 way because we can not just using a $2.
    - how many ways can we pay $4 using coin $2 -> 1 way because we can just use a $2, i.e. 4 = 2 + 2
    - how many ways can we pay $5 using coin $2 -> 0 way because we can not just using a $2.
    - coin $5 cannot be used until the amount is $5
    Here's what the matrix looks like

                0  1  2  3  4  5     
            0    1  0  0  0  0  0

            2    1  0  1  0  1  0           <------DP MATRIX

            5    1   

    - however we have coin $2 which can pay $2 and $4 so $1 and $3 still remain 0 (0 way)
                    0  1  2  3  4  5     
            0       1  0  0  0  0  0

            2       1  0  1  0  1  0

            5       1  0  1  0  1  1        <------DP MATRIX

    - seeing the above pattern we can deduce the transition formula as follow:
    if j >= coin[i - 1];
        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]], where i, j > 0
        
        To breakdown the formula we have
        - dp[i - 1][j]: number of ways we know we can pay amount j if we don't use coin i
        - dp[i][j - coins[i - 1]]: number of ways we can pay if we use coin i
    else 
        dp[i][j] = dp[i - 1][j], meaning we just drop the coin.

*/

using namespace std;

vector<int> coins;
int amount;

class Solution {
public:
    int change(int sum, vector<int>& coins) {
        if (sum == 0) {
            return 1;
        }
        if (coins.empty()) {
            return 0;
        }

        const int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        for (int i = 0; i < sum + 1; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i < n + 1; i++) {
            dp[i][0] = 1;
        }
        cout << dp << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            cout << dp << endl;
        }
        cout << dp << endl;
        return dp[n][sum];
    }
};

int main(int argc, char const* argv[]) {
    coins = stringToIntVector("[2,5]"), amount = 5;
    cout << Solution().change(amount, coins) << endl;

    return 0;
}

