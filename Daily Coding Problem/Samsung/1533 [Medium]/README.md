# Problem statement
Good morning! Here's your coding interview problem for today.

This problem was asked by Samsung.

A group of houses is connected to the main water plant by means of a set of pipes. A house can either be connected by a set of pipes extending directly to the plant, or indirectly by a pipe to a nearby house which is otherwise connected.

For example, here is a possible configuration, where `A`, `B`, and `C` are houses, and arrows represent pipes:

```
A <--> B <--> C <--> plant
```

Each pipe has an associated cost, which the utility company would like to minimize. Given an undirected graph of pipe connections, return the lowest cost configuration of pipes such that each house has access to water.

In the following setup, for example, we can remove all but the pipes from `plant` to `A`, `plant` to `B`, and `B` to `C`, for a total cost of `16`.

```
pipes = {
    'plant': {'A': 1, 'B': 5, 'C': 20},
    'A': {'C': 15},
    'B': {'C': 10},
    'C': {}
}
```

# Solution
This problem is a classic example of the Minimum Spanning Tree (MST) problem, which can be solved using Kruskal's or Prim's algorithm. In this case, we'll use Kruskal's algorithm, which is more suitable for sparse graphs.

The idea is to find the minimum cost edges that connect all the nodes (houses and the water plant) in such a way that there are no cycles.

`Graph` structure to store the graph and edges, and a `DisjointSets` structure for the disjoint set operations required by Kruskal's algorithm. The `kruskalMST` function finds the minimum spanning tree and returns the minimum cost to connect all houses to the water plant. The main function initializes the graph with the given pipes and their costs, and then computes the minimum cost.