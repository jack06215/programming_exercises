#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

void knapsack01(int capacity, vector<vector<int>>& items) {
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

void knapsack_unbound(int capacity, vector<vector<int>>& items) {
    vector<vector<int>> dp(items.size() + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i < items.size() + 1; i++) {
        for (int k = 1; k < capacity + 1; k++) {
            int weight = items[i - 1][0];
            int value = items[i - 1][1];
            if (k >= weight) {
                dp[i][k] = max(dp[i - 1][k], value + dp[i][k - weight]);
            }
            else {
                dp[i][k] = dp[i - 1][k];
            }
        }
    }
    cout << dp << endl;
}

int main() {
    int capacity = 7;
    vector<vector<int>> items = { {3, 9},{5, 15},{1, 2} };
    knapsack01(capacity, items);
    knapsack_unbound(capacity, items);
    return 0;
}