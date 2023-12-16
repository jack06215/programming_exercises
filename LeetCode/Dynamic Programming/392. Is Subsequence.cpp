#include <iostream>
#include <string>
#include <vector>
#include "../prettyprint.h"

using namespace std;


class Solution {
    vector<vector<int>> dp;
public:
    int isSubsequence(string s, string t) {
        // init dp array
        dp.resize(s.size() + 1);
        for (int i = 0; i < dp.size(); i++) {
            dp[i].resize(t.size() + 1, 0);
        }
        cout << dp << endl;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << dp << endl;
        return dp[s.size()][t.size()] == s.size() ? true : false;
    }
};

class Solution {
    vector<vector<bool>> dp;
public:
    bool isSubsequence(string s, string t) {
        // init dp array
        dp.resize(s.size() + 1);
        for (int i = 0; i < dp.size(); i++) {
            dp[i].resize(t.size() + 1, false);
        }

        // empty str is subsequence of empty str
        dp[0][0] = true;
        for (int i = 1; i <= t.size(); i++) {
            dp[0][i] = true;
        }

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main(int argc, const char* argv[]) {
    cout << Solution().isSubsequence("abc", "ahbgdc") << endl;

    return 0;
}
