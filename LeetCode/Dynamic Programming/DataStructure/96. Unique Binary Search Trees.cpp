#include <vector>

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

        int temp = 0;
        for (int i = begin; i <= end; ++i) {
            int left = helper(begin, i - 1);
            int right = helper(i + 1, end);
            temp += left * right;
        }
        return dp[begin][end] = temp;
    }

    int numTrees(int n) {
        dp.resize(20, vector<int>(20, -1));
        return helper(0, n - 1);
    }
};