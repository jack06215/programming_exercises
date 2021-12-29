#include <vector>
#include <iostream>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int n = nums.size() - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                return false;
            }
            nums[i + 1] = max(nums[i + 1], nums[i] - 1);
        }
        return true;
    }
};

int main() {
    auto nums = stringToIntVector("[2,3,1,1,4]");
    cout << boolalpha << Solution().canJump(nums) << endl;

    return 0;
}
