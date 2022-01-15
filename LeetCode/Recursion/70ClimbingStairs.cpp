#include <vector>
#include <iostream>

using namespace std;

class Solution {
    vector<int> memo;
    int _climbStairs(int n) {
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = _climbStairs(n - 1) + _climbStairs(n - 2);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        memo.resize(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;
        return _climbStairs(n);
    }
};

