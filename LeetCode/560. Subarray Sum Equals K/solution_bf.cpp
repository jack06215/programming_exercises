#include <vector>
#include <iostream>
#include <unordered_map>
#include <numeric>
#include <deque>
#include <functional>
#include "../codec.h"
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        size_t sz = nums.size();
        
        // start adding up from index 1
        vector<int> running_sum(sz + 1);
        
        // if nothing is added, the sum is 0
        running_sum[0] = 0; 
        
        // running sum from index 1 to sz + 1
        inclusive_scan(cbegin(nums), cend(nums), 
                       begin(running_sum) + 1,
                       plus<>{});
        
        // go through all possible combinations (O^2)
        int res = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = i; j < sz; j++) {
                if (running_sum[j + 1] - running_sum[i] == k) {
                    res++;
                }
            }
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

