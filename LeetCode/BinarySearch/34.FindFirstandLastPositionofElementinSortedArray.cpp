#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return { lower_bound(nums, target), upper_bound(nums, target) };
    }
private:
    int lower_bound(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        if (left == nums.size() || nums[left] != target) {
            return -1;
        }
        return left;
    }

    int upper_bound(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        // left points to the first element this is greater than target.
        --left;
        if (left < 0 || nums[left] != target) {
            return -1;
        }
        return left;
    }
};