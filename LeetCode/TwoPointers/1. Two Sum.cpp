#include <vector>
#include <algorithm>
#include "../codec.h"
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> lookup;
        for (auto i = 0; i < nums.size(); ++i) {
            lookup.push_back({ nums[i], i });     // (value, index)
        }
        sort(lookup.begin(), lookup.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int val = lookup[left].first + lookup[right].first;
            if (val == target) {
                return { lookup[left].second, lookup[right].second };
            }
            else if (val > target) {
                right--;
            }
            else {
                left++;
            }
        }
        return {};
    }
};

int main() {
    auto s = Solution();
    auto nums = stringToIntVector("[2,7,11,15]");
    int target = 9;
    cout << s.twoSum(nums, target) << endl;

    return 0;
}
