#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "../prettyprint.h"
#include "../codec.h"

using namespace std;

/*
    The first part loop on routes and record stop to routes mapping in to_route.
    The second part is general bfs. Take a stop from queue and find all connected route.
    The hashset seen record all visited stops and we won't check a stop for twice.
    We can also use a hashset to record all visited routes, or just clear a route after visit.
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> to_routes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j : routes[i]) {
                to_routes[j].push_back(i);
            }
        }
        cout << to_routes << endl;
        queue<pair<int, int>> bfs;
        bfs.push({ source, 0 });
        unordered_set<int> seen = { source };
        while (!bfs.empty()) {
            int stop = bfs.front().first;
            int bus = bfs.front().second;
            bfs.pop();
            if (stop == target) {
                return bus;
            }
            for (int i : to_routes[stop]) {
                for (int j : routes[i]) {
                    if (seen.find(j) == seen.end()) {
                        seen.insert(j);
                        bfs.push({ j, bus + 1 });
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};

int main(int argc, char const* argv[]) {
    vector<vector<int>> routes = read2DVectorFromString("[[1,2,7],[3,6,7]]");
    cout << Solution().numBusesToDestination(routes, 1, 6) << endl;
    return 0;
}

