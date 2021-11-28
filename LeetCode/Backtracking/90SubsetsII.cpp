#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

vector<int> arr;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        subsetsWithDup(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> candidate;
    void subsetsWithDup(vector<int>& nums, int n) {
        res.push_back(candidate);
        for (int i = n; i < nums.size(); i++) {
            if (i == n || nums[i] != nums[i - 1]) {
                candidate.push_back(nums[i]);
                subsetsWithDup(nums, i + 1);
                candidate.pop_back();
            }
        }
    }
};


int main(int argc, char const* argv[]) {
    arr = stringToIntVector("[1,2,2]");
    cout << Solution().subsetsWithDup(arr) << endl;
    return 0;
}

