#include <vector>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        memo.resize(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        return _tribonacci(n);
    }
private:
    vector<int> memo;
    int _tribonacci(int n) {
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = _tribonacci(n - 1) + _tribonacci(n - 2) + _tribonacci(n - 3);
        return memo[n];
    }
};
