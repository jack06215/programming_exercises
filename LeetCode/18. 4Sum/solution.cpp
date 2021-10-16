#include <vector>
#include <iostream>
#include <set>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) {
            return {{}};
        }

        set<vector<int>> unique_ans; 
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int a = 0; a < n - 3; a++) { // range [0:n-3]
            for(int b = a + 1; b < n - 2; b++) { // range [1:n-2]
                for(int c = b + 1, d = n - 1; c < d; c++) { // range [2:n-2]
                    if (nums[a] + nums[b] + nums[c] + nums[d] > target) {
                        d--; // a, b, c move from left-right and d is right-left
                        c--; // c has to be smaller than d
                    }
                    else if (nums[a] + nums[b] + nums[c] + nums[d] == target) {
                        // storing unique solution
                        unique_ans.insert({ nums[a], nums[b], nums[c], nums[d] });
                    }
                }
            }
        }
        for(auto it: unique_ans) ans.push_back(it);
        return ans;
    }
};

class Solution2 {
public:
    void findNSum(vector<int>& nums, int target, int NSum, int left_n, vector<int> two_sum_res, vector<vector<int>> &res){
        // 1. not enough nums for NSum
        // 2. the 4sum will smaller/larger than target no matter what
        if(nums.size() - left_n < NSum || 
           target < (long)nums[left_n] * NSum || target > (long)nums.back() * NSum) {
            return;
        }
        
        // 2Sum problem
        if(NSum == 2) {
            int left = left_n;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    two_sum_res.push_back(nums[left]);
                    two_sum_res.push_back(nums[right]);
                    
                    res.push_back(two_sum_res);
                    
                    two_sum_res.pop_back();
                    two_sum_res.pop_back();
             
                    // skip duplicates
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                    
                } 
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
            
            
        }
        else if(NSum > 2) {            
            for(int i = left_n; i < nums.size() - NSum + 1; i++) {
                if(i == left_n || i > left_n && nums[i - 1] != nums[i]) {
                    two_sum_res.push_back(nums[i]);
                    // target - nums[i]: new target value
                    // NSum - 1: (N - 1)Sum
                    // last_n_idx + 1: move left by 1 step
                    findNSum(nums, target - nums[i], NSum - 1, i + 1, two_sum_res, res);
                    two_sum_res.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> twoSumRes;
        twoSumRes.reserve(2);
        vector<vector<int>> res;
        int NSum = 4;
        // target: our target value
        // NSum: 4Sum
        // last_n_idx + 1: start from last element
        findNSum(nums, target, NSum, 0, twoSumRes, res);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> input = { 1, 0, -1, 0, -2, 2 };
    cout << s.fourSum(input, 0) << endl;
    return 0;
}

