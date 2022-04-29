#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> res;
    void backtrack(int n, int k, int s, vector<int>& combs) {
        if (k == 0) {
            res.push_back(combs);
            return;
        }

        for (int i = s; i <= n; i++) {
            combs.push_back(i);
            backtrack(n, k - 1, i + 1, combs);
            combs.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combs;
        backtrack(n, k, 1, combs);
        return res;
    }
};
