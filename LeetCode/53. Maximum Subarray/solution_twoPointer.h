#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        else if (nums.size() == 1) {
            return nums[0];
        }

        int current_max = 0;
        int global_max = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); i++) {
            current_max = std::max(nums[i], nums[i] + current_max);
            if (current_max > global_max) 
                global_max = current_max;
        }
        return global_max;
    }
};
