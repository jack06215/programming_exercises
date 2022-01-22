#include <vector>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        constexpr int inf = numeric_limits<int>::max();
        vector<vector<int>>dp(n, vector<int>(n, inf));

        // Symmertric
        for (int i = 0; i < edges.size(); i++) {
            dp[edges[i][0]][edges[i][1]] = edges[i][2];
            dp[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        // Floyd Warshall's shortest path algorithm
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dp[j][i] != inf && dp[i][k] != inf) {
                        dp[j][k] = min(dp[j][k], (dp[j][i] + dp[i][k]));
                    }
                }
            }
        }

        int smallest_count = inf;
        int res;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dp[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (smallest_count >= count) {
                smallest_count = count;
                res = i;
            }
        }
        return res;
    }
};