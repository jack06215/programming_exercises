#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // two consecutive elements must be unuqie to avoid duplicated answer
            int j = i + 1;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // k is always starts from the end
            int k = nums.size() - 1;
            while (j < k) {
                // great! we found an answer
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({ nums[i], nums[j], nums[k] });

                    // skip repeated answer j
                    int val1 = nums[j];
                    while (j < k && nums[j] == val1) {
                        j++;
                    }

                    // skip repeated anwser k
                    int val2 = nums[k];
                    while (j < k && nums[k] == val2) {
                        k--;
                    }
                }

                // move pointer accordingly
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }

                else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
            }
        }
        return res;
    }
};
