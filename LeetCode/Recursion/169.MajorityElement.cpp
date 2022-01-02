#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }
private:
    int majorityElement(const vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        const int m = l + (r - l) / 2;
        const int ml = majorityElement(nums, l, m);
        const int mr = majorityElement(nums, m + 1, r);
        if (ml == mr) {
            return ml;
        }
        return count(nums.begin() + l, nums.begin() + r + 1, ml) >
            count(nums.begin() + l, nums.begin() + r + 1, mr)
            ? ml : mr;
    }
};