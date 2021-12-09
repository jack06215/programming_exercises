#include <iostream>
#include <vector>
#include <list>
#include "../prettyprint.h"

using namespace std;

class Graph {
public:
    vector<vector<int>> edge;
    vector<unsigned char> visited;
    int n_vertices;

    Graph(int n) : n_vertices(n) {
        edge.resize(n);
        visited.resize(n, false);
    }

    void add_edge(int v, int w) {
        edge[v].push_back(w);
    }

    void reset() {
        visited.resize(n_vertices, false);
    }
};

void bfs(Graph& g, int s) {
    list<pair<int, int>> q;
    g.visited[s] = true;
    q.push_back({ s, 0 });
    while (!q.empty()) {
        auto val = q.front();
        cout << val.first << " " << val.second << endl;
        q.pop_front();
        for (auto i : g.edge[val.first]) {
            if (!g.visited[i]) {
                g.visited[i] = true;
                q.push_back({ i, val.second + 1 });
            }
        }
    }
}

void dfs(Graph& g, int s) {
    cout << s << endl;
    g.visited[s] = true;
    for (auto next : g.edge[s]) {
        if (!g.visited[next]) {
            g.visited[next] = true;
            dfs(g, next);
        }
    }
}

int main() {
    Graph g(5);
    g.add_edge(0, 1);

    g.add_edge(1, 2);
    g.add_edge(1, 3);

    g.add_edge(2, 4);

    g.add_edge(3, 4);
    g.add_edge(4, 0);

    // bfs(g, 0);
    
    dfs(g, 0);

    return 0;
}