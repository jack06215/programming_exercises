#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        using pfi = pair<double, int>;
        unordered_map<int, vector<pfi>> graph;

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(succProb[i], edges[i][1]);
            graph[edges[i][1]].emplace_back(succProb[i], edges[i][0]);
        }
        priority_queue<pfi, vector<pfi>> pq;
        pq.emplace(1.0, start);

        vector<bool> visited(n, false);
        vector<double> dst(n, 0);
        dst[start] = 1.0;

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            dst[node] = dist;
            visited[node] = true;

            if (node == end) {
                return dist;
            }

            for (auto [d, child] : graph[node]) {
                if (visited[child]) {
                    continue;
                }
                dst[child] = max(dst[child], d * dist);
                pq.emplace(dst[child], child);
            }
        }

        return 0;
    }
};
