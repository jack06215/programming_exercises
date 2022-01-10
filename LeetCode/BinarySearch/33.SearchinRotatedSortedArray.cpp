#include <vector>

using namespace std;

/*
    Let's say nums looks like this: [12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

    Because it's not fully sorted, we can't do normal binary search. But here comes the trick:

    If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
    [12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]

    If target is let's say 7, then we adjust nums to this:
    [-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

    And then we can simply do ordinary binary search.
*/

class Solution {
    const int maxx = numeric_limits<int>::max();
    const int minn = numeric_limits<int>::min();
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int num = (nums[mid] < nums[0]) == (target < nums[0])
                ? nums[mid]
                : target < nums[0] ? minn : maxx;
            if (num == target) {
                return mid;
            }
            else if (num < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return -1;
    }
};
