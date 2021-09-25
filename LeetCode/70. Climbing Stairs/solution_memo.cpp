#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (memo.size() == 0 && n > 1) {
            memo.resize(n + 1);
            memo[0] = 0;
            memo[1] = 1;
            memo[2] = 2;
        }
        if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }
        else {
            memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
            return memo[n];
        }
    }
private:
    vector<int> memo;
};
