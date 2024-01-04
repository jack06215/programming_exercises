#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        
        // initially push the last element into the stack 
        stk.push(n - 1);
        
        // start traversing the array from the right.
        int i = n - 2;
        while (i >= 0) {
            // can't jump from current index to the index at the top of the stack
            if (nums[i] < stk.top() - i) {
                i--;
            }
            // pop stack to see the farthest step we can jump from the current index.
            // for instance [2,3,1,1,4], since we can directly jump from index 1 to index 4,
            // we pop the intermediate indices (2,3).
            else {
                int idx;
                while (!stk.empty() && nums[i] >= stk.top() - i) {
                    idx = stk.top();
                    stk.pop();
                }
                stk.push(idx);
                stk.push(i);
                i--;
            }
        }
        return stk.size() - 1;
    }
};