#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            int left = 0;
            int right = n - 1;
            // keep pushing increasing subsequence
            if (result.empty() || result[right] < nums[i]) {
                result.push_back(nums[i]);
            }
            // 
            else {
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (result[mid] >= nums[i]) {
                        right = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                result[left] = nums[i];
            }
        }
        return result.size();
    }
};
