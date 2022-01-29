#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int helper(int begin, int end) {
        if (begin > end) {
            return 1;
        }

        if (dp[begin][end] != -1) {
            return dp[begin][end];
        }

        int res = 0;
        for (int i = begin; i <= end; i++) {
            int left = helper(begin, i - 1);
            int right = helper(i + 1, end);
            res += left * right;
        }
        dp[begin][end] = res;
        return dp[begin][end];
    }

    int numTrees(int n) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        int res = helper(0, n - 1);
        cout << dp << endl;
        return res;
    }
};

class Solution {
    vector<int> dp;
public:
    int helper(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1 || n == 2) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += helper(i - 1) * helper(n - i);
        }
        dp[n] = res;
        cout << dp << endl;
        return dp[n];
    }
    int numTrees(int n) {
        dp.resize(n + 1, -1);
        dp[n] = helper(n);
        return dp[n];
    }
};

int main(void) {
    cout << Solution().numTrees(5) << endl;
    return 0;
}