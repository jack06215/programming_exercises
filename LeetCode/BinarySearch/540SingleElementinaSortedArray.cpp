#include <vector>

using namespace std;

class Solution2 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // odd number: compare next
            // even number: comapre previous
            if (nums[mid] == nums[mid ^ 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // found answer
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            // even number
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid - 1]) {
                    right = mid - 2;
                }
                else if (nums[mid] == nums[mid + 1]) {
                    left = mid + 2;
                }

            }
            // odd number
            else {
                if (nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                }
                else if (nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                }
            }
        }
        return nums[left];
    }
};
