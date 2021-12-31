#include <vector>
#include <iostream>
#include "../codec.h"
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int N = nums.size();
        int ending = N - 1;
        for (int i = N - 2; i > -1; i--) {
            if (nums[i] >= ending - i) {
                ending = i;
            }
        }
        return ending == 0;
    }
};

int main() {
    vector<int> nums = stringToIntVector("[2,3,1,1,4]");
    cout << Solution().canJump(nums) << endl;
    return 0;
}
