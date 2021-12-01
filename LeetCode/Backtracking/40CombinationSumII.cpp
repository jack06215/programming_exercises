#include <vector>
#include <iostream>
#include <algorithm>
#include "../codec.h"
#include "../prettyprint.h"

using namespace std;

vector<int> candidates;
int target;

// class Solution {
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(begin(candidates), end(candidates));
//         _combinationSum2(candidates, target, 0);
//         return res;
//     }
// private:
//     vector<vector<int>> res;
//     vector<int> combs;

//     void _combinationSum2(vector<int>& candidates, int target, int begin) {
//         if (target == 0) {
//             res.push_back(combs);
//             return;
//         }
//         for (int i = begin; i < candidates.size(); i++) {
//             if (target >= candidates[i] && (i == begin || candidates[i] != candidates[i - 1])) {
//                 combs.push_back(candidates[i]);
//                 _combinationSum2(candidates, target - candidates[i], i + 1);
//                 combs.pop_back();
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        _combinationSum2(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> combs;

    void _combinationSum2(vector<int>& candidates, int target, int begin) {
        if (target == 0) {
            res.push_back(combs);
        }
        else if (target < 0) {
            return;
        }
        if (combs.size() == candidates.size()) {
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            if (i == begin || candidates[i] != candidates[i - 1]) {
                combs.push_back(candidates[i]);
                _combinationSum2(candidates, target - candidates[i], i + 1);
                combs.pop_back();
            }
        }
    }
};

int main(int argc, char const* argv[]) {
    candidates = stringToIntVector("[10,1,2,7,6,1,5]");
    target = 8;
    cout << Solution().combinationSum2(candidates, target) << endl;
    return 0;
}

