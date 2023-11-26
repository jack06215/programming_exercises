#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Edge {
  char src, dest;
  int weight;
};

struct Graph {
  map<char, vector<pair<char, int>>> adjList;
  vector<Edge> edges;

  void addEdge(char src, char dest, int weight) {
    adjList[src].push_back(make_pair(dest, weight));
    adjList[dest].push_back(make_pair(src, weight)); // Since the graph is undirected
    edges.push_back({ src, dest, weight });
  }
};

struct DisjointSets {
  map<char, char> parent;
  map<char, int> rank;

  char find(char i) {
    if (parent[i] != i)
      parent[i] = find(parent[i]);
    return parent[i];
  }

  void unite(char x, char y) {
    char xroot = find(x);
    char yroot = find(y);

    if (rank[xroot] < rank[yroot])
      parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
      parent[yroot] = xroot;
    else {
      parent[yroot] = xroot;
      rank[xroot]++;
    }
  }
};

int kruskalMST(Graph& graph) {
  int minCost = 0;
  vector<Edge> result;

  sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) {
    return a.weight < b.weight;
    });

  DisjointSets ds;

  for (auto& p : graph.adjList)
    ds.parent[p.first] = p.first, ds.rank[p.first] = 0;

  for (auto& e : graph.edges) {
    char x = ds.find(e.src);
    char y = ds.find(e.dest);

    if (x != y) {
      result.push_back(e);
      minCost += e.weight;
      ds.unite(x, y);
    }
  }

  // Print the result
  for (auto& e : result)
    cout << e.src << " - " << e.dest << ": " << e.weight << endl;

  return minCost;
}

int main() {
  Graph g;
  g.addEdge('A', 'C', 15);
  g.addEdge('B', 'C', 10);
  g.addEdge('plant', 'A', 1);
  g.addEdge('plant', 'B', 5);
  g.addEdge('plant', 'C', 20);

  int minCost = kruskalMST(g);
  cout << "Minimum Cost: " << minCost << endl;

  return 0;
}
