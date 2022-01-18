#include <vector>
#include "../codec.h"

using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size();

        // # of missing numbers in [nums[0], nums[i]]
        auto n_missing = [&](int i) { return nums[i] - nums[0] - i; };

        // find the first index l s.t. nMissing(l) >= k
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (n_missing(mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[left - 1] + (k - n_missing(left - 1));
    }
};

int main(int argc, char const* argv[]) {
    auto nums = stringToIntVector("[4,7,9,10]");
    cout << Solution().missingElement(nums, 3) << endl;
    return 0;
}

