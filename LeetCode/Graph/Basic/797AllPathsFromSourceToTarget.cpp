#include <vector>
#include <iostream>
#include <queue>
#include "../../prettyprint.h"

using namespace std;

// NOTE: since Grapth is DAG => we don't need visited lookup table
class Solution {
    vector<int> path;
    vector<vector<int> > res;
public:
    void dfs(int node, int target, vector<vector<int>>& graph) {
        path.push_back(node);
        if (node == target) {
            res.push_back(path);
        }

        for (int child : graph[node]) {
            dfs(child, target, graph);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dfs(0, n - 1, graph);
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> res;
    int target;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        bfs(graph, 0);
        return res;
    }
    void bfs(vector<vector<int>>& adj, int src) {
        queue<pair<int, vector<int>>> bfs;
        bfs.push({ src, { src } });
        while (!bfs.empty()) {
            auto [node, path] = bfs.front();
            bfs.pop();
            if (node == target) {
                res.push_back(path);
            }
            for (auto nextNode : adj[node]) {
                path.push_back(nextNode);
                bfs.push({ nextNode, path });
                path.pop_back();
            }
        }
    }
};
