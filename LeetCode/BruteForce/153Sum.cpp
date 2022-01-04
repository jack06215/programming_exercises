#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len < 3) {
            return {};
        }
        
        // set stores unique elements only (i.e. duplicate triplets not added)
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        // compare all cases in O(N^3) time
        for(int i = 0;i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++) {
                for(int k = j + 1; k < len; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0) {
                        res.insert({ nums[i], nums[j], nums[k] });
                    }
                }
            }
        }
        
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};
