#include <vector>

using namespace std;

class Solution {
    vector<int> memo;

    int _fib(int n) {
        if (memo[n] != -1) {
            return memo[n];
        }
        memo[n] = _fib(n - 1) + _fib(n - 2);
        return memo[n];
    }
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        memo.resize(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;
        return _fib(n);
    }
};
