#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        // Reverse the whole array
        // 7 6 5 4 3 2 1
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        // 4 5 6 7 3 2 1
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining (n - k) elements
        // 4 5 6 7 1 2 3
        reverse(nums.begin() + k, nums.end());
    }
};
