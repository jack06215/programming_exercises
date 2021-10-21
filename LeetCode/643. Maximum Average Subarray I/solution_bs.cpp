#include <vector>
#include <iostream>
#include <limits>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        // find the min and max of the numbers and then perform binary search within this range
        for (const auto& num: nums) {
            maxx = max(maxx, static_cast<double>(num));
            minn = min(minn, static_cast<double>(num));
        }
        // check if there is a continuous subarray with at least length k that has average greater than mid
        while (maxx - minn > eps) {
            double mid = minn + (maxx - minn) / 2;
            if (isValid(&nums[0], n, mid, k)) {
                minn = mid;
            }
            else {
                maxx = mid;
            }
        }
        return minn;
    }
private:
    double eps = 1e-5;
    double maxx = numeric_limits<double>::max();
    double minn = numeric_limits<double>::min();

    bool isValid(int nums[], int nums_size, double target, int k) {
        // accumulate the first k items difference with target
        int i = 0;
        double sum = 0;
        while (i < k) {
            sum += nums[i++] - target;
        }
        // if the sum is greater than 0, we can return true
        if (sum >= 0) return true;
        double prev = 0;
        double minn = 0;
        // Otherwise we need to see if the remaining elements' difference can form a sum greater than min sum
        while (i < nums_size) {
            sum += nums[i] - target;
            prev += nums[i - k] - target;
            i++;
            minn = min(minn, prev);
            if (sum >= minn) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> input_arr = {1, 12, -5, -6, 50, 3};
    cout << s.findMaxAverage(input_arr, 4) << endl;
    return 0;
}

