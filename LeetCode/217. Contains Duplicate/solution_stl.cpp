#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return ( std::adjacent_find(nums.begin(), nums.end()) != nums.end() );
    }
};
