#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <limits>
#include "../../../prettyprint.h"

using namespace std;


class Solution {
public:
    void dijkstra(int start, int n_edges, vector<vector<pair<int, int>>>& edges) {
        // make graph
        // [distance, node]
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({ 0, start });

        // create distance array and initialize infinite
        vector<int> dst(n_edges, numeric_limits<int>::max());
        dst[start] = 0;

        while (!pq.empty()) {
            auto [distance, node] = pq.top();
            pq.pop();

            if (distance > dst[node]) {
                continue;
            }
            dst[node] = distance;

            // [next node, next distance]
            for (auto [nn, nd] : edges[node]) {
                // found shorter route
                if (distance + nd < dst[nn]) {
                    pq.push({ distance + nd, nn });
                }
            }
        }
        cout << dst << endl;
        return;
    }
};


int main(int argc, const char* argv[]) {
    // [node, distance]
    vector<vector<pair<int, int>>> edges;

    // direction: left -> right
    //        5    7
    //     1 -- 3 -- 5
    //   1/   2/ 1\ /3 
    // 0 -- 2 -- 4
    //    3    8
    //
    edges = {
        {{1,1}, {2,3}},
        {{3,5}},
        {{3,2}, {4,8}},
        {{4,1}, {5,7}},
        {{5,3}},
        {}
    };
    Solution().dijkstra(0, edges.size(), edges);
    cout << edges << endl;
    return 0;
}