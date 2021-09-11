#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 1);
        for (auto num: nums) {
            left = max(left, num);
        }
        while(left < right) {
            int mid = (left + right) / 2;
            int n_bags = 1;
            for (int i = 0, sum = 0; i < nums.size(); i++) {
                sum += nums[i + 1];
                if (sum + nums[i] > mid) {
                    sum = 0;
                    n_bags++;
                }
            }     
            
            if (n_bags > m) { // bags are too small, 
                left = mid + 1;
            }
            else{
                right = mid;
            }      
        }
        return left;
    }
};
