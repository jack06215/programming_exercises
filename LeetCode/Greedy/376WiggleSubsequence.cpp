#include <vector>
#include <stack>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        stack<int> stk;
        if (nums.size() == 1) {
            return 1;
        }
        if (nums.size() == 2) {
            return nums[0] == 0 && nums[1] == 0 ? 1 : 2;
        }
        for (int i = 1; i < nums.size(); i++) {
            // current diff
            int diff = nums[i] - nums[i - 1];

            // find fist diff
            if (stk.empty()) {
                if (diff != 0) {
                    stk.push(diff);
                }
                else {
                    continue;
                }
            }
            
            // determine whether there is a new wiggle element
            else {
                // wiggle element is where previous diff and current diff has opposite sign (i.e. up and down)
                if ((stk.top() > 0 && diff < 0) || (stk.top() < 0 && diff > 0)) {
                    stk.push(diff);
                }
            }
        }
        return stk.size() + 1;
    }
};

