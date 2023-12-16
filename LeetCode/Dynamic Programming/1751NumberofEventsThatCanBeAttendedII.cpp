#include <iostream>
#include <vector>
#include <algorithm>
#include "../prettyprint.h"

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        const int size = events.size();

        // compare by end day function
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        };

        // sort events by their end day
        sort(begin(events), end(events), comp);

        vector<vector<int>> dp(size + 1, vector<int>(k + 1));
        for (int i = 1; i <= size; ++i) {
            // end day of previous event (the other field are not important so fill 0)
            vector<int> prev_endday = { 0, events[i - 1][0], 0 };

            // find next event! (the next event that does not overlap with the current one)
            const int next_event = lower_bound(begin(events), begin(events) + i, prev_endday, comp) - begin(events);

            // dp[i][j] ==> max value we can get by attending at most j events among events[0..i]
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[next_event][j - 1] + events[i - 1][2]);
            }
        }
        cout << dp << endl;
        return dp[size][k];
    }
};

int main() {
    vector<vector<int>> input;
    int k;

    input = { {1,2,4},{3,4,3},{2,3,1} };
    k = 2;
    cout << Solution().maxValue(input, k) << endl;
    return 0;
}