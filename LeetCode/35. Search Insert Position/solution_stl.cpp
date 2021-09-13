#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator insert_iter = lower_bound(nums.begin(), nums.end(), target);
        return (distance(nums.begin(), insert_iter));
    }
};
