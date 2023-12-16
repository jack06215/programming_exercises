#include <iostream>
#include <queue>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

// Approach: 
// We're basically adding all the activites that start on a same given day.
// Out of these we now attend the one which ends at the earliest possible.
// We increment the day and hence remove all the activites which coudn't be attended.

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int i = 0;
        int day = 0;
        int res = 0;
        int n = size(events);

        // while we still some events we probably can attend
        while (!pq.empty() || i < n) {
            // Add candidate event(s)
            if (pq.empty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // Attending the activity ending at the earliest.
            pq.pop();
            res++;
            day++;

            // Removing all the activites which now cannot be attended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> events = read2DVectorFromString("[[1,2],[2,3],[3,4]]");
    cout << Solution().maxEvents(events) << endl;
    return 0;
}
