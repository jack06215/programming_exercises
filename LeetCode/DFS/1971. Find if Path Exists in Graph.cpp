#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if (start == end) return true;

        // Create adjacency list
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // DFS setup
        vector<bool> visited(n, false);
        return dfs(graph, visited, start, end);
    }

    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int current, int end) {
        if (current == end) {
            return true;
        }
        visited[current] = true;

        for (int neighbor : graph[current]) {
            if (!visited[neighbor] && dfs(graph, visited, neighbor, end)) {
                return true;
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
