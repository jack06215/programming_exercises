#include <iostream>
#include <vector>
#include <algorithm>
#include "../prettyprint.h"

class Solution {
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *std::max_element(begin(nums), end(nums));
        while (left < right) {
            // binary search: start from middle
            int middle = left + (right - left) / 2;
            
            // if the penality is "middle", then how many operations are needed
            int n_operation = 0;
            for (int x: nums) {
                n_operation += (x - 1) / middle;
            }
            
            // the typical: adjust "left" or "right" to "middle"
            // repeat the binary search again
            if (n_operation <= maxOperations) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        // the result is the "left"
        return left;
    }
};

int main() {
    std::vector<int> input;
    int maxOperation;
    Solution s = Solution();

    input = {2, 4, 8, 2};
    maxOperation = 4;
    std::cout << s.minimumSize(input, maxOperation) << std::endl;
    return 0;
}