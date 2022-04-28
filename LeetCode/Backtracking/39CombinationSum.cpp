#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

vector<int> candidates;
int target;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> combs;
    void combinationSum(vector<int>& candidates, int target, int begin) {
        if (target == 0) {
            res.push_back(combs);
            return;
        }
        for (int i = begin; i < candidates.size(); ++i) {
            if (target >= candidates[i]) {
                combs.push_back(candidates[i]);
                combinationSum(candidates, target - candidates[i], i);
                combs.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> combs;
    void combinationSum(vector<int>& candidates, int target, int begin) {
        if (target == 0) {
            res.push_back(combs);
            return;
        }
        else if (target < 0) {
            return;
        }
        for (int i = begin; i < candidates.size(); ++i) {
            combs.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i);
            combs.pop_back();
        }
    }
};

int main(int argc, char const* argv[]) {
    candidates = stringToIntVector("[2,3,5]");
    target = 8;
    cout << Solution().combinationSum(candidates, target) << endl;
    return 0;
}
