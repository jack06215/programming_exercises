#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(const int& num: nums) {
            if (s.count(num) > 0) {
                return false;
            }
            s.insert(num);
        }
        return true;
    }
};
