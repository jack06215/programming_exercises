#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int a = *(end(nums) - 1);
        int b = *(end(nums) - 2);
        int c = *(begin(nums));
        int d = *(begin(nums) + 1);

        return (a * b) - (c * d);
    }
};
