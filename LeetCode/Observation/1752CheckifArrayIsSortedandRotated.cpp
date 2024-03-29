#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int num_decreases = nums.back() > nums.front();
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                num_decreases++;
            }
        }
        return num_decreases <= 1;
    }
};