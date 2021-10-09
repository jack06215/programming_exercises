#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int infinity_int = numeric_limits<int>::max();
        int ans = infinity_int;
        int left{0}, right{0}, prefix_sum{0};
        while (left < nums.size()) {
            while (prefix_sum < s && right < nums.size()) {
                prefix_sum += nums[right++];
            }
            cout << prefix_sum << endl;
            if (prefix_sum < s) {
                break;
            }
            ans = min(ans, right - left);      
            prefix_sum = prefix_sum - nums[left++];
        }
        return ans == infinity_int ? 0 : ans;      
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << s.minSubArrayLen(7, nums) << endl;
    return 0;
}

