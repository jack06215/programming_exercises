#include <iostream>
#include <vector>
#include "../prettyprint.h"

using namespace std;



class Graph {
public:
    int n_vertices;
    vector<vector<int>> adj;
    vector<int> visited;
    Graph(int n) : n_vertices(n) {
        adj.resize(n);
        visited.resize(n, 0);
    }

    void addEdge(int v, int val) {
        adj[v].push_back(val);
    }

    void dfs() {
        for (int i = 0; i < n_vertices; i++) {
            cout << i << endl;
        }
    }
};

/*
{
    0: [1,2,3],
    1: [2,3],
    3: [1],
}

*/
int main(int argc, char const* argv[]) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(3, 1);

    cout << g.adj << endl;
    
    return 0;
}
