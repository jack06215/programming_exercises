#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<pair<int, int>> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            lookup.push_back({nums[i], i});     // (value, index)
        }
        sort(lookup.begin(), lookup.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int val = lookup[left].first + lookup[right].first;
            if (val == target) {
                result.push_back(lookup[left].second);
                result.push_back(lookup[right].second);
                break;
            }
            else if (val > target) {
                right--;
            }
            else {
                left++;
            }
        }
        return result;
    }
};
