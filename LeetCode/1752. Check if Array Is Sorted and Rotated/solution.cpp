#include <vector>
#include <iostream>
#include <algorithm>

// class Solution {
// public:
//     bool check(std::vector<int>& nums) {
//         int size = nums.size();
//         for (int i = 0, k = 0; i < size; i++) {
//             if (nums[i] > nums[(i + 1) % size] && ++k > 1) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool check(const std::vector<int> &nums)
    {
        auto itr = std::is_sorted_until(nums.begin(), nums.end());
        if (itr == nums.end()) {
            return true;
        }
        if (!std::is_sorted(itr, nums.end())) {
            return false;
        }
        return nums.back() <= nums.front();
    }
};

int main() {
    Solution s = Solution();
    std::vector<int> input_seq;

    input_seq = {3,4,5,1,2};
    std::cout << s.check(input_seq) << std::endl;
    return 0;
}