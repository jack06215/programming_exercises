#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        int res = numeric_limits<int>::min();
        for (int head = 0, tail = 0, total = 0; tail < size; tail++) {
            total += nums[tail];
            if (tail - head == k) {
                total -= nums[head];
                head++;
            }
            if (tail - head == k - 1) {
                res = max(res, total);
            }
        }
        return res * 1.0 / k;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<int> nums = { 1,12,-5,-6,50,3 };
    cout << s.findMaxAverage(nums, 4) << endl;
    return 0;
}

