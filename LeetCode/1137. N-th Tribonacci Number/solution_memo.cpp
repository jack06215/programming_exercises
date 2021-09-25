#include <vector>

using namespace std;

class Solution {
public:
    int helper_func(int n, int* arr) {
        if (arr[n] != -1) {
            return arr[n];
        }
        arr[n] = helper_func(n - 1, arr) + helper_func(n - 2, arr) + helper_func(n - 3, arr);
        return arr[n];
    }
    
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1 || n == 2) {
            return 1;
        }
        memo.resize(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        int res = helper_func(n, &memo[0]);
        return res;
    }
private:
    vector<int> memo;
};
