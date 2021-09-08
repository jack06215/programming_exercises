#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    virtual vector<int> searchRange(vector<int>& nums, int target) = 0;
};

class Solution1: public Solution {
public:
    int binarySearch(vector<int> nums, int target, bool is_find_first) {
        int left = 0;
        int right = nums.size();
        int result = -1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = mid;
                (is_find_first) ? right = mid : left = mid + 1;
            }
            else if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return { binarySearch(nums, target, true), binarySearch(nums, target, false) };
    }
};

int main(void) {
    Solution *s;
    s = new Solution1();
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;
    std::cout << s->searchRange(nums, target) << endl;
    return 0;
}