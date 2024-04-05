#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        queue<int> que;
        int minElementIndex = -1;
        int maxElementIndex = -1;
        int64_t res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                que.push(nums[i]);
                if (nums[i] == minK) {
                    minElementIndex = que.size();
                }
                if (nums[i] == maxK) {
                    maxElementIndex = que.size();
                }
                if (minElementIndex != -1 && maxElementIndex != -1) {
                    res += min(minElementIndex, maxElementIndex);
                }

            }
            else {
                queue<int>().swap(que);
                minElementIndex = -1;
                maxElementIndex = -1;
            }
        }
        return res;
    }
};
