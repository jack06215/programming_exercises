#include <vector>
#include <iostream>
#include <algorithm>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

vector<vector<int>> intervals;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        cout << intervals << endl;
        const int n = intervals.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n) {
                // either i covers i + 1
                if (intervals[i][0] <= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][1]) {
                    count++;
                    // here we replace next interval with current one because it is covered by current interval
                    intervals[i + 1] = intervals[i];
                }
                // or they are distinct
                else if (intervals[i][0] >= intervals[i + 1][0] && intervals[i][1] <= intervals[i + 1][1]) {
                    count++;
                }
            }
        }
        cout << intervals << endl;
        return n - count;

    }
};

class Solution2 {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // if two intervals share the same start point, put the longer one to be the first.
        sort(begin(intervals), end(intervals),
            [](const auto& left, const auto& right) {
                return left[0] == right[0] ? right[1] < left[1] : left[0] < right[0];
            });
        cout << intervals << endl;
        int count = 0;
        int end;
        int prev_end = 0;
        for (const auto& interval : intervals) {
            end = interval[1];
            // if current interval is not covered by the previous one
            if (prev_end < end) {
                count++;
                prev_end = end;
            }
        }
        return count;
    }
};

int main(int argc, char const* argv[]) {
    // intervals = read2DVectorFromString("[[1,4],[3,6],[2,8]]");
    intervals = read2DVectorFromString("[[2,9],[2,8],[2,10]]");
    cout << Solution2().removeCoveredIntervals(intervals);

    return 0;
}
