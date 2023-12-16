#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> duplicated_flags;
        for (int i = 0; i < nums.size(); i++) {
            if (!duplicated_flags.count(nums[i])) {
                duplicated_flags[nums[i]] = i;
            }
            else if (i - duplicated_flags[nums[i]] <= k) {
                return true;
            }
            else {
                duplicated_flags[nums[i]] = i;
            }
        }
        return false;
    }
};
