#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <unordered_map>
#include "../../../prettyprint.h"
#include "../../../codec.h"

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<double, int>>> graph;

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(succProb[i], edges[i][1]);
            graph[edges[i][1]].emplace_back(succProb[i], edges[i][0]);
        }
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        pq.emplace(1.0, start);

        vector<bool> visited(n, false);
        vector<double> dst(n, 0);
        dst[start] = 1.0;


        pq.push({ 1.0, start });

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

int main() {
    auto edges = read2DVectorFromString("[[0,1],[1,2],[0,2]]");
    auto succProb = stringToDoubleVector("[0.5,0.5,0.2]");
    cout << Solution().maxProbability(3, edges, succProb, 0, 2) << endl;
}
