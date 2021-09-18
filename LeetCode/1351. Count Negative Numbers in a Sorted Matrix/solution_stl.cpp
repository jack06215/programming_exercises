#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n_cols = grid[0].size();
        
        int res = 0;
        for (auto arr: grid) {
            auto iter = find_if(arr.cbegin(), arr.cend(), [](int val){ return val < 0; });
            int count = n_cols - (iter - arr.begin());
            res += count;
        }
        return res;
    }
};