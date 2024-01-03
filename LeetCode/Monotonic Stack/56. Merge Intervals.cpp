#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) { return lhs[1] < rhs[1]; });
        for (auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            while (!res.empty() && start <= res.back()[1]) {
                start = min(start, res.back()[0]);
                res.pop_back();
            }
            res.push_back({ start, end });
        }
        return res;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    Solution sol;
    cout << sol.merge(intervals) << endl;
    return 0;
}
