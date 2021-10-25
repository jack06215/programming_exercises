#include <vector>
#include <deque>
#include <iostream>
#include <limits>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> prefix_sum(size + 1);
        deque<int> dq;
        // prefix sum
        for (int i = 0; i < size; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        
        // we want the smaller length, so let's assume it's some large number
        int res = numeric_limits<int>::max();
        
        for (int i = 0; i < size + 1; i++) {
            // we want know if there is a subarray such that nums[i] ~ nums[j - 1] is at least k
            // if exist, 
            while (!dq.empty() && prefix_sum[i] - prefix_sum[dq.front()] >= k) {
                // find the smaller one
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            // to keep the deque increasing.
            while (!dq.empty() && prefix_sum[i] < prefix_sum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    
    vector<int> nums = { 2,-1,2 };
    int k = 3;
    cout << s.shortestSubarray(nums, k) << endl;
    return 0;
}

