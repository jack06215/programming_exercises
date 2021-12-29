#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

uint64_t fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

uint64_t fib_memo(int n, vector<uint64_t>& memo) {
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    return memo[n];
}

void findMaxValue(int capacity, vector<vector<int>>& items) {
    vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i < items.size() + 1; i++) {
        for (int k = 1; k < capacity + 1; k++) {
            int weight = items[i - 1][0];
            int value = items[i - 1][1];
            if (k >= weight) {
                dp[i][k] = max(dp[i - 1][k], value + dp[i - 1][k - weight]);
            }
            else {
                dp[i][k] = dp[i - 1][k];
            }
        }
    }
    cout << dp << endl;
}

// void findMaxValue1D(int capacity, vector<vector<int>>& items) {
//     vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1, 0));
//     for () {

//     }
// }

int main() {
    // int n = 250;
    // vector<uint64_t> dp(n + 1, -1);
    // dp[0] = 0, dp[1] = 1;
    // cout << fib_memo(n, dp) << endl;

    int capacity = 7;
    vector<vector<int>> items = { {4, 9},{5, 15},{3, 8} };
    findMaxValue(capacity, items);
    return 0;
}