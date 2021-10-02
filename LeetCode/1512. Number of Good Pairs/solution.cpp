#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> count;
        for (int num: nums) {
            res = res + count[num];
            count[num] = count[num]+ 1;
        }
        return res;
    }
};
