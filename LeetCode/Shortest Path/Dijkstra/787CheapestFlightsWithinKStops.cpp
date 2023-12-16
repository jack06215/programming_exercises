#include <vector>
#include <tuple>
#include <queue>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using tiii = tuple<int, int, int>;
        constexpr int maxx = numeric_limits<int>::max();
        // graph[city] = [ {to_city, cost}, ... ]
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }

        // pq = { total cost, to stop, k stop }
        priority_queue<tiii, vector<tiii>, greater<>> pq;
        pq.emplace(0, src, 0);

        // dist[source to destination] = { cheapest cost, number of flight(s) }
        vector<pair<int, int>> dist(n, { maxx, maxx });
        dist[src] = { 0, 0 };
        while (pq.size()) {
            auto [total_cost, to_city, n_flights] = pq.top();
            pq.pop();
            if (to_city == dst) {
                return total_cost;
            }
            if (n_flights <= k) {
                for (auto& [next_city, cost] : graph[to_city]) {
                    auto [new_cost, new_n_flights] = dist[next_city];

                    if (total_cost + cost < new_cost || n_flights + 1 < new_n_flights) {
                        pq.emplace(total_cost + cost, next_city, n_flights + 1);
                        dist[next_city] = min(dist[next_city], { total_cost + cost, n_flights + 1 });
                    }
                }
            }
        }
        return -1;
    }
};