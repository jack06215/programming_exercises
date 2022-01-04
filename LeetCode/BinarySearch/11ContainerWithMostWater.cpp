#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = numeric_limits<int>::min();

        while (left < right) {
            int left_h = height[left];
            int right_h = height[right];

            max_area = max(max_area, (right - left) * min(right_h, left_h));

            if (left_h < right_h) {
                ++left;
            }
            else {
                --right;
            }
        }
        return max_area;
    }
};
