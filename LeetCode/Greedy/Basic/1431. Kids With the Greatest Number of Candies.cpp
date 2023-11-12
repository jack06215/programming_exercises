#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto maxx = numeric_limits<int>::min();
        vector<bool> res;
        for (auto it : candies) {
            maxx = max(maxx, it);
        }
        for (auto it : candies) {
            res.push_back(it + extraCandies >= maxx);
        }
        return res;
    }
};
