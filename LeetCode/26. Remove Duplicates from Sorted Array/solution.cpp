#include <iostream>
#include <vector>
#include "../prettyprint.h"

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        int p1 = 0;
        for(int p2 = 0; p2 < nums.size(); p2++) {
            if(nums[p1] != nums[p2]) {
                nums[++p1] = nums[p2];
            }
        }
        return p1 + 1;
    }
};

int main() {
    Solution s;
    std::vector<int> nums;

    nums = {1,1,2};
    s.removeDuplicates(std::ref(nums));
    std::cout << s.removeDuplicates(std::ref(nums)) << std::endl;
    return 0;
}