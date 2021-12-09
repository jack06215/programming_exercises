#include <vector>
#include <iostream>
#include <deque>
#include "../prettyprint.h"

using namespace std;

class Graph {
public:
    int n_vertices;
    vector<vector<int>> adj;
    deque<vector<int>> q;
    vector<int> visited;
    Graph(int n) : n_vertices(n) {
        adj.resize(n);
        visited.resize(n, 0);
    }

    void addEdge(int v, int val) {
        adj[v].push_back(val);
    }

    void bfs(int v) {
        // (node, depth)
        q.push_back({ v, 0 });
        while (!q.empty()) {
            auto val = q.front(); q.pop_front();
            cout << val[0] << " " << val[1] << endl;
            for (int i = v + 1; i < adj.size(); i++) {
                if (!visited[i]) {
                    q.push_back({ i, ++val[1] });
                    visited[i] = 1;
                }
            }
        }
    }

};

/*
    0: [1],
    1: [2, 3],
    2: [4],
    3: [4]
*/

int main(int argc, char const* argv[]) {
    Graph g(4);
    g.addEdge(0, 1);

    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(2, 4);

    g.addEdge(3, 4);

    cout << g.adj << endl;
    g.bfs(0);

    return 0;
}
