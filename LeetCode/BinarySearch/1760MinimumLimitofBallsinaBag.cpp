#include <iostream>
#include <vector>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int minimumSize(std::vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(begin(nums), end(nums));
        while (left < right) {
            int middle = left + (right - left) / 2;

            // if the penality is "middle", then how many operations are needed
            int n_operation = 0;
            for (int x : nums) {
                n_operation += (x - 1) / middle;
            }

            if (n_operation <= maxOperations) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> input;
    int maxOperation;
    Solution s = Solution();

    input = { 2, 4, 8, 2 };
    maxOperation = 4;
    cout << s.minimumSize(input, maxOperation) << endl;
    return 0;
}