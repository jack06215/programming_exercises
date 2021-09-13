#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result = 0;
        for(const auto& val: nums) {
            if (val < target) result++;
            else break;
        }
        return result;
    }
};