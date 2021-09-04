#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "../prettyprint.h"

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> result(nums.size(), 0);
        std::sort(nums.begin(), nums.end());
        int head = 0;
        int tail = nums.size() - 1;
        int current = nums.size() - 1;
        while (head <= tail) {
            int left_squared = nums[head] * nums[head];
            int right_squared = nums[tail] * nums[tail];

            if (left_squared >= right_squared) {
                result[current] = left_squared;
                head++;
            }
            else {
                result[current] = right_squared;
                tail--;
            }
            current--;
        }
        return result;
    }
};

int main () {
    Solution s = Solution();
    std::vector<int> input_seq;

    input_seq = {-4, -1, 0, 3, 10};
    std::cout << s.sortedSquares(input_seq) << std::endl;
    input_seq = {-7,-3,2,3,11};
    std::cout << s.sortedSquares(input_seq) << std::endl;
    return 0;
}
