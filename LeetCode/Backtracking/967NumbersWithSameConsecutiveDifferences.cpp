#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> res;
public:
    void backtrack(int& n, int pos, int& k, int num) {
        if (pos == n) {
            res.push_back(num);
            return;
        }
        if (pos > n) {
            return;
        }
        int last_digit = num % 10;
        int next_digit;

        next_digit = last_digit + k;
        if (next_digit <= 9) {
            int temp = num;
            num = 10 * num + next_digit;
            backtrack(n, pos + 1, k, num);
            num = temp;
        }

        next_digit = last_digit - k;
        if (k != 0 && next_digit >= 0) {
            int temp = num;
            num = 10 * num + next_digit;
            backtrack(n, pos + 1, k, num);
            num = temp;
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i <= 9; ++i) {
            backtrack(n, 1, k, i);
        }
        return res;
    }
};