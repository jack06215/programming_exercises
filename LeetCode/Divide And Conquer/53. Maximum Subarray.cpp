#include <vector>
#include <limits>

using namespace std;

class Solution {
    vector<int> arr;
public:
    int crossSum(int left, int right, int mid) {
        int ans1 = numeric_limits<int>::min();
        int ans2 = numeric_limits<int>::min();
        // from mid to 0, keep the max
        for (int i = mid, sum = 0; i >= left; i--) {
            sum += arr[i];
            ans1 = max(ans1, sum);
        }
        // from mid to n, keep the max
        for (int i = mid + 1, sum = 0; i <= right; i++) {
            sum += arr[i];
            ans2 = max(ans2, sum);
        }
        // add them together
        return ans1 + ans2;
    }

    int _maxSubArray(int left, int right) {
        if (left >= right) {
            return arr[left];
        }

        // divide the the original problem into two equal parts:
        // [0, n - 1] -> [0, mid] & [mid + 1, n - 1]
        // so the longest subarray must be in either [0, mid] or [mid, n - 1]
        int mid = left + (right - left) / 2;
        int sumLeft = _maxSubArray(left, mid);
        int sumRight = _maxSubArray(mid + 1, right);

        // ...or it could also be cross from the two [left...mid...right]
        // here we add from mid to left and from mid to right and keep the two temp max and then add them together
        int sumCross = crossSum(left, right, mid);

        // return the maximum
        return max({ sumCross, sumLeft, sumRight });
    }

    int maxSubArray(vector<int>& nums) {
        arr = nums;
        int n = nums.size();
        return _maxSubArray(0, n - 1);
    }
};
