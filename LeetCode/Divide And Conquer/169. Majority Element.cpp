#include <vector>
#include <algorithm>

using namespace std;

/*
    Input: nums = [3,2,3]
    Output: 3

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return _majorityElement(nums, 0, nums.size() - 1);
    }
private:
    int _majorityElement(const vector<int>& nums, int left, int right) {
        // base case: no more search space
        if (left == right) {
            return nums[left];
        }

        // divide and conquer:
        // split nums in half until it cannot be splited
        int mid = left + (right - left) / 2;
        int ml = _majorityElement(nums, left, mid);
        int mr = _majorityElement(nums, mid + 1, right);

        // majority from both side are the same
        if (ml == mr) {
            return ml;
        }
        // ...are different, then we need to count and return the majority
        auto start = begin(nums) + left;
        auto end = begin(nums) + right + 1;
        return count(start, end, ml) > count(start, end, mr) ? ml : mr;
    }
};
