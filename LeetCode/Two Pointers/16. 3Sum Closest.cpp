#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = static_cast<int>(10e4);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target) {
                    return target;
                }
                else if (sum > target) {
                    k--;
                }
                else {
                    j++;
                }

                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
            }
        }
        return res;
    }
};
