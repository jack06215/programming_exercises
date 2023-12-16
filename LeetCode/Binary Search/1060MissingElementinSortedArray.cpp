#include <vector>
#include "../codec.h"

using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size();

        // count of missing numbers in [nums[0], nums[i]]
        auto count_missing_element = [&](int i) { return nums[i] - nums[0] - i; };

        // find the first index such that count_missing_element(left) >= k
        while (left < right) {
            int mid = left + (right - left) / 2;
            // if from [left, mid] the count bigger than k, then k-th element must within LHS
            if (count_missing_element(mid) >= k) {
                right = mid;
            }
            // otherwise we reduce search space
            else {
                left = mid + 1;
            }
        }
        return nums[left - 1] + (k - count_missing_element(left - 1));
    }
};

// 7 + (3 - 2) = 8
// 4 + (1 - 0) = 5
int main(int argc, char const* argv[]) {
    auto nums = stringToIntVector("[4,7,9,10]");
    cout << Solution().missingElement(nums, 3) << endl;
    return 0;
}

