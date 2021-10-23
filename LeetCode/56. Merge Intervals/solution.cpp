#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

/*
252 Meeting Rooms
253 Meeting Rooms II
435 Non-overlapping Intervals
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), 
            [](auto a, auto b){ return a[1] < b[1]; });
        for (auto& interval: intervals) {
            int left = interval[0];
            int right = interval[1];
            while (!res.empty() && left <= res.back()[1]) {
                left = min(left, res.back()[0]);
                res.pop_back();
            }
            res.push_back({left, right});
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

