#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>> pq;
        vector<int> coordinates;
        for (auto b : buildings) {
            coordinates.emplace_back(b[0]);
            coordinates.emplace_back(b[1]);
        }
        sort(coordinates.begin(), coordinates.end());
        int m = unique(coordinates.begin(), coordinates.end()) - coordinates.begin();
        int j = 0;
        int prev_height = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            while (j < buildings.size() && buildings[j][0] <= coordinates[i]) {
                pq.emplace(buildings[j][2], buildings[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top().second <= coordinates[i]) {
                pq.pop();
            }
            int curr_height = pq.empty() ? 0 : pq.top().first;
            if (curr_height != prev_height) {
                ans.push_back({ coordinates[i], curr_height });
                prev_height = curr_height;
            }
        }
        return ans;
    }
};
