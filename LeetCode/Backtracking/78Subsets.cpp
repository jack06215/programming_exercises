#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;
vector<int> inputs;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        subsets(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> candidate;
    void subsets(vector<int>& nums, int begin) {
        res.push_back(candidate);
        for (int i = begin; i < nums.size(); i++) {
            candidate.push_back(nums[i]);
            subsets(nums, i + 1);
            candidate.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
    inputs = stringToIntVector("[1,2,2]");
    cout << Solution().subsets(inputs) << endl;
    return 0;
}

