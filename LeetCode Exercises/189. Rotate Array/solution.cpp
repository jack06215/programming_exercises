#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        // for large k, i.e. k >= nums.size()
        k = k % nums.size();
        // elements in LHS and RHS are swapped, but reversed order!
        std::reverse(nums.begin(), nums.end());
        // bring LHS back to order
        std::reverse(nums.begin(), nums.begin() + k);
        // bring RHS back to order
        std::reverse(nums.begin() + k, nums.end());
    }
};

void rotate(std::vector<int>& v, int k) {
    std::rotate(v.rbegin(),                     // start
                v.rbegin() + k % v.size(),      // new start element
                v.rend());                      // end
}

int main() {
    Solution s = Solution();
    std::vector<int> input_seq;

    input_seq = {1,2,3,4,5,6,7};
    s.rotate(input_seq, 3);
    std::cout << input_seq << std::endl;
    return 0;
}