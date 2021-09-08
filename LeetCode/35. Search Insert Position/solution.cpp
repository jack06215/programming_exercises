#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    virtual int searchInsert(vector<int>& nums, int target) = 0;
};

class SolutionBinarySearch: public Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1; 
            }
        }
        return left;
    }
};

class SolutionWalkthrough: public Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = 0;
        for(const auto& val: nums) {
            if (val < target) result++;
            else break;
        }
        return result;
    }
};

class SolutionSTL: public Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator insert_iter = lower_bound(nums.begin(), nums.end(), target);
        return (distance(nums.begin(), insert_iter));
    }
};

int main(void) {
    Solution *s;
    //s = new SolutionBinarySearch();
    // s = new SolutionWalkthrough();
    s = new SolutionSTL();
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 5;
    cout << s->searchInsert(nums, target) << endl;
    return 0;
}