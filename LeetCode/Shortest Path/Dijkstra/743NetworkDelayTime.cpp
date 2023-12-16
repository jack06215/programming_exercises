#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        using pii = pair<int, int>;
        constexpr int maxx = numeric_limits<int>::max();
        vector<vector<pii>> vp(N + 1);
        for (const auto& time : times) {
            vp[time[0]].push_back({ time[1], time[2] });
        }
        vector<bool> visited(N + 1, false);
        vector<int> d(N + 1, maxx);
        d[0] = 0;
        d[K] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({ 0, K });
        while (!pq.empty()) {
            auto [c, u] = pq.top(); pq.pop();
            if (visited[u]) {
                continue;
            }
            for (auto to : vp[u]) {
                auto [v, w] = to;
                if (c + w < d[v]) {
                    d[v] = c + w;
                    pq.push({ d[v], v });
                }
            }
            visited[u] = true;
        }
        int res = *max_element(begin(d), end(d));
        return res == maxx ? -1 : res;
    }
};
