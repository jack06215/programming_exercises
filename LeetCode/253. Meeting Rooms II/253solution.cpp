#include <iostream>
#include <vector>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        vec.push_back({ intervals[0][0], intervals[0][1] });
        for (int i = 1, j = 0; i < intervals.size(); i++) {
            for (; j < vec.size(); j++) {
                if (intervals[i][0] >= vec[j][1]) { // not overlapping, can be done in 1 room
                    vec[j][0] = min(vec[j][0], intervals[i][0]);
                    vec[j][1] = max(vec[j][1], intervals[i][1]);
                    break;
                }
            }
            if (j == vec.size()) {
                vec.push_back({ intervals[i][0], intervals[i][1] });
            }
        }
        cout << vec << endl;
        return vec.size();
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    vector<vector<int>> intervals;

    intervals = { {0,30},{5,10},{15,20} };
    cout << s.minMeetingRooms(intervals) << endl;

    return 0;
}
