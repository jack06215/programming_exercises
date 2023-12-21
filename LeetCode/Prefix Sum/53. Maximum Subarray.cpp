#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = numeric_limits<int>::min();
        int minPrefixSum = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;
            maxSum = max(maxSum, prefixSum - minPrefixSum);
            minPrefixSum = min(minPrefixSum, prefixSum);
        }

        return maxSum;
    }
};
