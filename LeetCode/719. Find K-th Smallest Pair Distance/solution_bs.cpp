#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;
const int N = 100000;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> freq(N, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ++freq[abs(nums[i] - nums[j])];
            }
        }
        for (int i = 0; i < N; i++) {
            if (freq[i] >= k) {
                return i;
            }
            k -= freq[i];
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums = {1, 6, 1};
    cout << s.smallestDistancePair(nums, 3) << endl;
    return 0;
}
