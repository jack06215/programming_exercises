#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if (start == end) {
            return true;
        }

        // Create adjacency list
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Visit all the adjacent nodes
            for (const auto &neighbor : graph[node]) {
                if (neighbor == end) {
                    return true;
                }
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    int n = 4; // Number of nodes
    vector<vector<int>> edges = { {0, 1}, {0, 2}, {1, 2}, {2, 3} };
    int start = 0, end = 3;

    bool result = solution.validPath(n, edges, start, end);
    cout << (result ? "Path exists" : "Path does not exist") << endl;

    return 0;
}
