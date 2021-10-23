#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		vector<int> u(height.size(), 0);
		partial_sum(height.cbegin(), height.cend(), u.begin(), 
			[](auto a, auto b) { return max(a, b); });
		int ans = transform_reduce(height.cbegin(), height.cend(), 	u.cbegin(), 0, plus{}, 
			[](auto a, auto b) { return abs(a - b); });
		return ans;
    }
};

class Solution2 {
public:
    int trap(vector<int>& heights) {
        if (heights.empty()) return 0; 
        int res = 0;
        
		// - go though the heights from left to right
		// - trapping rains occurs when 
		//     (1) heights[i1] < heights[i2], where i1 < i2, here we "look back" the stk as we go through
		//     (2) a "concave area" where water cen be trapped
        stack<int> stk;   
        for(int i = 0; i < heights.size(); i++) {
			// 
            while (!stk.empty() && heights[i] > heights[stk.top()]) {
                // we have a concave area
				int concaveIdx = stk.top();
				stk.pop();
                
				// we have left
                if (!stk.empty()) {
					int leftIdx = stk.top();
					int width = i - leftIdx - 1;
					int height = min(heights[i], heights[leftIdx]) - heights[concaveIdx];
					res += height * width;
				}
            }
            stk.push(i);
        }
        return res;
    }
};

int main (void) {
	Solution2 s;
	vector<int> vec = { 2, 1, 2, 4, 2, 3, 5, 2, 4, 7 };
	cout << s.trap(vec) << endl;
	return 0;
}
