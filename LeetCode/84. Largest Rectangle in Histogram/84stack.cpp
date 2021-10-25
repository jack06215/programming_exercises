#include <vector>
#include <stack>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // we only update the area when heights[i] is shorter than the previous one
        // what if the last one is the highest amognst all ?
        // we append a new dummy data of height 0, so now the logic will work as expected
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

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> heights;

    heights = { 2,4 };
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}

