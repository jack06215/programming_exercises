#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }
private:
    int majorityElement(const vector<int>& nums, int left, int right) {
        // base case: no more search space
        if (left == right) {
            return nums[left];
        }

        // divide and conquer:
        // split nums in half until it cannot be splited
        int mid = left + (right - left) / 2;
        int ml = majorityElement(nums, left, mid);
        int mr = majorityElement(nums, mid + 1, right);

        // return majority element
        if (ml == mr) {
            return ml;
        }
        auto start = begin(nums) + left;
        auto end = begin(nums) + right + 1;
        return count(start, end, ml) > count(start, end, mr) ? ml : mr;
    }
};