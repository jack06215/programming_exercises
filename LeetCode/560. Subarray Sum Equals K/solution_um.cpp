#include <vector>
#include <iostream>
#include <unordered_map>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // dictionary to keep the counting of prefix sum (running sum)
        // running sum = 0 when nothing is added, i.e. {0, 1}
        unordered_map<int, int> mp{{0, 1}};
        int res{0}, sum{0};
        for (const auto& num: nums) {
            // running sum
            sum += num;
            // nums[0] + nums[1] + ... + nums[i] => prefix_sum(0, i), where i is the running sum up to index i.
            // Now we are looking for a subarray within given range such that
            // prefix_sum(0, i) - prefix_sum(0, j) == k,  where j < i
            // rearrange we get:
            //      prefix_sum(0, i) - k = prefix_sum(0, j)
            
            
            // if sum - k exists, add it up
            if(mp.count(sum - k)) {
                res += mp[sum - k]; 
            }
            // then we update current running sum counter by 1
            mp[sum]++;
        }
        return res;   
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums = { 1, 1, 1 };
    cout << s.subarraySum(nums, 2) << endl;
    return 0;
}

