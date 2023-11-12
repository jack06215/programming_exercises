#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // dummy data so that the loop will work correctly
        heights.push_back(0);

        stack<int> stk;
        int res = 0;
        int i = 0;
        int size = heights.size();
        while (i < size) {
            if (stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i++);
            }
            else {
                int height = heights[stk.top()]; stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, height * width);
            }
        }
        return res;
    }
};
