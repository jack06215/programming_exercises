#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        memo.resize(n + 1, -1);
        memo[0] = 1, memo[1] = 1;
        return solve(n, &memo[0]);
    }
private:
    vector<int> memo;

    int solve(int n, int* arr) {
        if (arr[n] != -1) {
            return arr[n];
        }
        arr[n] = solve(n - 1, arr) + solve(n - 2, arr);
        return arr[n];
    }
};

int main(int argc, char const* argv[]) {
    int n = 4;
    cout << Solution().climbStairs(n) << endl;
}

