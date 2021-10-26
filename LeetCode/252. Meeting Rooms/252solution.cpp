#include <iostream>
#include <vector>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merged;
        if (intervals.size() == 0) {
            return true;
        }
        sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) { return lhs[0] < rhs[0]; });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    vector<vector<int>> intervals;

    intervals = { {0,30},{5,10},{15,20} };
    cout << s.canAttendMeetings(intervals) << endl;

    intervals = { {7,10},{2,4} };
    cout << s.canAttendMeetings(intervals) << endl;
    return 0;
}
