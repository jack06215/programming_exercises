#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <functional>
#include <limits>
#include "../../prettyprint.h"
#include "../../codec.h"

using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // graph[city] = [ {to_city, cost}, ... ]
        vector<vector<pair<int, int>>> graph(n);
        for (auto& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        cout << graph << endl;
        // pq = { total cost, to stop, k stop }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        // from src to src: cost is 0 and num of flight is 0
        pq.emplace(0, src, 0);

        // dist[source to destination] = { cheapest cost, number of flights w.r.t. cheapest cost }
        vector<pair<int, int>> dist(n, { numeric_limits<int>::max(), numeric_limits<int>::max() });
        // from src to city 0: cost is 0 and number of flight is also 0
        dist[src] = { 0, 0 };

        while (pq.size()) {
            auto [total_cost, to_city, n_flights] = pq.top();
            pq.pop();

            // we reached the destination
            if (to_city == dst) {
                return total_cost;
            }

            // destination not reached yet, but we still have n flights left
            if (n_flights <= k) {
                // for each destination in graph[i]
                for (auto& [next_city, cost] : graph[to_city]) {
                    // check if the route is better than previous one
                    auto [current_cost, current_n_flights] = dist[next_city];
                    if (total_cost + cost < current_cost || n_flights + 1 < current_n_flights) {
                        // push new candidate
                        pq.emplace(total_cost + cost, next_city, n_flights + 1);
                        // update the table
                        dist[next_city] = min(dist[next_city], { total_cost + cost, n_flights + 1 });
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char* argv[]) {
    int n = 3;
    int src = 0;
    int dst = 2;
    int k = 1;
    vector<vector<int>> flights = read2DVectorFromString("[[0,1,50],[1,2,100],[0,2,160]]");

    cout << Solution().findCheapestPrice(n, flights, src, dst, k);

    return 0;
}
