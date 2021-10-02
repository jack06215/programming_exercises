#include <algorithm>
#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left{0}, right{1000000};
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                // int j = 0;
                // while (j < n && nums[j] <= nums[i] + mid) j++;
                int j = upper_bound(nums.begin(), nums.end(), nums[i] + mid) - nums.begin();
                cnt += (j - i) - 1;
            }
            if (cnt < k) 
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

