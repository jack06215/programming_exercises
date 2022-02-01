#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;
vector<int> inputs;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, vector<int>(), res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int begin, vector<int>&& candidate, vector<vector<int>>& res) {
        res.push_back(candidate);
        for (int i = begin; i < nums.size(); i++) {
            candidate.push_back(nums[i]);
            dfs(nums, i + 1, move(candidate), res);
            candidate.pop_back();
        }
    }
};

int main(int argc, char const* argv[]) {
    inputs = stringToIntVector("[1,2,2]");
    cout << Solution().subsets(inputs) << endl;
    return 0;
}

