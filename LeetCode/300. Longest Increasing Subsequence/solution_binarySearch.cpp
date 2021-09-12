#include <vector>
#include <iostream>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int cur_size = result.size();
            if (result.size() == 0 || result[cur_size - 1] < nums[i]) {
                result.push_back(nums[i]);
            }
            else {
                int left = 0;
                int right = cur_size - 1;
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (result[mid] >= nums[i]) {
                        right = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                result[left] = nums[i];
            }
        }
        return result.size();
    }
};

int main() {
    Solution s;
    std::vector<int> input = { 10, 9, 2, 5, 3, 7, 101, 18 };
    std::cout << s.lengthOfLIS(input) << std::endl;
    return 0;
}
