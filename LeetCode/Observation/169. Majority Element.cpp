#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm
        int count = 0;
        int candidate = nums[0];
        for (auto& num : nums) {
            // update new candidate
            if (count == 0) {
                candidate = num;
            }
            // majority count + 1
            if (num == candidate) {
                count++;
            }
            // majority count - 1
            else {
                count--;
            }
        }
        return candidate;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};
