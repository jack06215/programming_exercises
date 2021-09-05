#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

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

int main (void) {
	Solution s = Solution();
	vector<int> vec = { 2, 1, 2, 4, 2, 3, 5, 2, 4, 7 };
	cout << s.trap(vec) << endl;
	return 0;
}
