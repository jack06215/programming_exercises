#include <vector>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        const int kMod = 1e9 + 7;
        const int maxx = numeric_limits<int>::max();

        // build adjacent graph
        using pii = pair<int, int>;
        vector<vector<pii>> node(n + 1);
        for (auto& edge : edges) {
            node[edge[0]].push_back({ edge[1], edge[2] });
            node[edge[1]].push_back({ edge[0], edge[2] });
        }

        // Shortest distance from n to x
        vector<int> dist(n + 1, maxx);
        // base case: distance is 0 at end node
        dist[n] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        // base case: distance is 0 at end node
        q.push({ 0, n });
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            // distance is bigger, skip
            if (dist[u] < d) {
                continue;
            }
            for (auto [v, w] : node[u]) {
                // distance is bigger, skip
                if (dist[u] + w >= dist[v]) {
                    continue;
                }
                // we have a valid path
                dist[v] = dist[u] + w;
                q.push({ dist[v], v });
            }
        }

        vector<int> dp(n + 1, maxx);
        function<int(int)> dfs = [&](int u) {
            // we reached the end node
            if (u == n) {
                return 1;
            }
            // retrive solution from memo
            if (dp[u] != maxx) {
                return dp[u];
            }
            // calculate 
            int ans = 0;
            for (auto [v, w] : node[u]) {
                if (dist[u] > dist[v]) {
                    ans = (ans + dfs(v)) % kMod;
                }
            }
            dp[u] = ans;
            return dp[u];
        };
        return dfs(1);
    }
};
