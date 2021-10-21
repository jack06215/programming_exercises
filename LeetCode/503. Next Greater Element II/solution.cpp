#include <vector>
#include <stack>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            s.push(nums[i]);
        }
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[i] >= s.top()) s.pop();
            if (s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(nums[i]);
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

