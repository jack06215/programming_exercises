#include <iostream>
#include <vector>
#include "../../prettyprint.h"

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    // Number of ways to have sum j with i cards
    vector<vector<int>> dp(4, vector<int>(K + 1, 0));

    // Base case: There's only one way to have a sum of 0 (by choosing no cards)
    dp[0][0] = 1;

    for (int i = 1; i <= 3; i++) { // For each of the three cards
        for (int j = 0; j <= K; j++) { // For each possible sum up to K
            for (int x = 1; x <= N; x++) { // For each card value from 1 to N
                if (j >= x) { // If the current sum can accommodate the card value
                    dp[i][j] += dp[i - 1][j - x];
                }
            }
        }
    }
    cout << dp[3] << endl;
    cout << dp[3][K] << endl; // The answer is the number of ways to reach K using all 3 cards

    return 0;
}
