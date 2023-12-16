#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            // keep pushing increasing subsequence
            if (result.empty() || result[result.size() - 1] < nums[i]) {
                result.push_back(nums[i]);
            }
            // binary search the where the smallest element in the array is >= mid
            else {
                int left = 0;
                int right = result.size() - 1;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (result[mid] >= nums[i]) {
                        right = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                // insert lower_bound element with x
                result[left] = nums[i];
            }
        }
        return result.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (res.empty() || res[res.size() - 1] < nums[i]) {
                res.push_back(nums[i]);
            }
            else {
                auto it = lower_bound(begin(res), end(res), nums[i]);
                *it = nums[i];
            }
        }
        return res.size();
    }
};
