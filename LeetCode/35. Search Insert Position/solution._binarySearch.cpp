#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        
        while (left < right) {
            // increment step by middle point
            int mid = left + (right - left) / 2;
            
            // we found the answer!
            if (nums[mid] == target) {
                return mid;
            }
            
            // too big, shift the high bound
            else if (nums[mid] >= target) {
                right = mid;
            }
            // too small, sift the low bound
            else {
                left = mid + 1; 
            }
        }
        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 5;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}