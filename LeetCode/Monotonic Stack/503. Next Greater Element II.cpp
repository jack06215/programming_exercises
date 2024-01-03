#include <vector>
#include <stack>
#include <iostream>
#include "../../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            stk.push(nums[i]);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= stk.top()) {
                stk.pop();
            }
            if (stk.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = stk.top();
            }
            stk.push(nums[i]);
        }
        return ans;
    }
};

int main(int argc, char const* argv[]) {
    Solution sol;
    vector<int> nums1 = { 1,2,3,4,3 };
    cout << sol.nextGreaterElements(nums1) << endl;
    return 0;
}

