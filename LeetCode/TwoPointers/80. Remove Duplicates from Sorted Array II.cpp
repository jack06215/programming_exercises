#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto val : nums) {
            if (i == 0 || i == 1 || nums[i - 2] != val) {
                nums[i] = val;
                i++;
            }
        }
        return i;
    }
};
