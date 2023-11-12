#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1;
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

                else {
                    k--;
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();

        // At least three elemnets needed for a triplet
        if (len == 0 || len < 3) {
            return {};
        }

        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++) {
            for (int j = i + 1; j < len - 1; j++) {
                for (int k = j + 1; k < len; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        s.insert({ nums[i], nums[j], nums[k] });
                    }
                }
            }
        }

        // Insert all unique triplets in result vector
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
