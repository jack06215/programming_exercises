#include <vector>

using namespace std;

class Solution {
public:
    int solve(int n, int* arr) {
        if (arr[n] != -1) {
            return arr[n];
        }
        arr[n] = solve(n - 1, arr) + solve(n - 2, arr);
        return arr[n];
    }
    
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        memo.resize(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;
        int res = solve(n, &memo[0]);
        return res;
    }
private:
    vector<int> memo;
};
