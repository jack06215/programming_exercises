#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string& a, string& b) {
        vector<vector<int>> dp(1000, vector<int>(1000, 0));
        const int m = a.size();
        const int n = b.size();
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (a[i] == b[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[m][n];
    }
};
