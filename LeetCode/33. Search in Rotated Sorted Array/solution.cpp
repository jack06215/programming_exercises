#include <vector>
#include <limits>
#include <iostream>

using namespace std;

/*
    Explanation

    Let's say nums looks like this: [12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

    Because it's not fully sorted, we can't do normal binary search. But here comes the trick:

    If target is let's say 14, then we adjust nums to this, where "inf" means infinity:
    [12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]

    If target is let's say 7, then we adjust nums to this:
    [-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

    And then we can simply do ordinary binary search.

    Of course we don't actually adjust the whole array but instead adjust only on the fly 
    only the elements we look at. And the adjustment is done by comparing both 
    the target and the actual element against nums[0].
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size();
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            
            int num = (nums[mid] < nums[0]) == (target < nums[0])
                    ? nums[mid]
                    : target < nums[0] ? numeric_limits<int>::min() : numeric_limits<int>::max();
                    
            if (num < target)
                head = mid + 1;
            else if (num > target)
                tail = mid;
            else
                return mid;
        }
        return -1;
    }
};
