#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> combination;
        _combinationSum3(n, 1, k);
        return res;
    }
private:
    vector<int> combs;
    vector<vector<int>> res;
    void _combinationSum3(int target, int begin, int need) {
        if (target == 0) {
            res.push_back(combs);
            return;
        }
        else if (!need)
            return;
        for (int i = begin; i != 10 && target >= i * need + need * (need - 1) / 2; ++i) {
            combs.push_back(i);
            _combinationSum3(target - i, i + 1, need - 1);
            combs.pop_back();
        }
    }
};