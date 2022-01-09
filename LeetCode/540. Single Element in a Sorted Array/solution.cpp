#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int result = 0;
        for (const auto& num: nums) {
            result = result ^ num;
        }
        return result;
    }
};

class Solution2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while( left < right ) {
            int mid = left + (right - left) / 2;
            // 
            if( nums[mid] == nums[mid ^ 1] ) // compare next/prev
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};
