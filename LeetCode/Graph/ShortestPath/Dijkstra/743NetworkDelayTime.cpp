#include <vector>
#include <limits>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        /*
            [
                [{ to_target, cost }],
                [{ to_target, cost }],
                ...
            ]
        */
        vector<vector<pair<int, int>>> from_network(N + 1);
        for (const auto& time : times) {
            from_network[time[0]].push_back({ time[1], time[2] });
        }
        vector<bool> visited(N + 1, false);
        
        vector<int> distance(N + 1, numeric_limits<int>::max());
        distance[0] = 0;
        distance[K] = 0;
        
        // [cost, from_node]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, K });
        
        while (!pq.empty()) {
            auto [c, node] = pq.top(); 
            pq.pop();
            if (visited[node]) {
                continue;
            }
            for (auto next : from_network[node]) {
                auto [to_target, cost] = next;
                if (c + cost < distance[to_target]) {
                    distance[to_target] = c + cost;
                    pq.push({ distance[to_target], to_target });
                }
            }
            visited[node] = true;
        }
        int res = *max_element(begin(distance), end(distance));
        return res == numeric_limits<int>::max() ? -1 : res;
    }
};