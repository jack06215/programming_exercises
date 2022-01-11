#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool check(const vector<int>& nums) {
        auto itr = is_sorted_until(nums.begin(), nums.end());
        if (itr == nums.end()) {
            return true;
        }
        if (!is_sorted(itr, nums.end())) {
            return false;
        }
        return nums.back() <= nums.front();
    }
};