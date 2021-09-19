#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (const int& target: nums1) {
            bool found_target = find(nums2.cbegin(), nums2.cend(), target) != nums2.cend();
            bool no_duplicated = find(res.cbegin(), res.cend(), target) == res.cend();
            if (found_target && no_duplicated) {
                res.emplace_back(target);
            }
        }
        return res;
    }
};
