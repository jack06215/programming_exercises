#include <vector>
#include <limits>
#include <iostream>

using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if (nums.size() == 1) {
        //     return nums[0] = target? 0 : -1;
        // }
        
        int left = 0;
        int right = nums.size();
        
        int iter = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num;
            cout << mid << " ";
            if ((nums[mid] < nums[0]) & (target < nums[0])) {
                num = nums[mid];
                cout << num << " " << iter << endl;
            }
            else {
                num = target < nums[0] ? numeric_limits<int>::min() : numeric_limits<int>::max();
                cout << num << " " << iter << endl;
            }
            
            
            if (num == target) {
                return mid;
            }
            else if (num < nums[left]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
            iter++;
        }
        return -1;
    }
};