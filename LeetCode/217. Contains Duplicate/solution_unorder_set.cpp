#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(const int& num: nums) {
            s.insert(num);
        }
        if(nums.size() != s.size()) {
            return true;
        }
        return false;   
    }
};
