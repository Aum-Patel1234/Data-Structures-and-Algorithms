#pragma once

#ifndef GRAPH_H
#define GRAPH_H
#include <utility> // Required for std::pair
#include <vector>

/*
 * This file provides sample data for an undirected graph.
 * The graph is represented as an "edge list," which is an array of pairs.
 * Each pair {u, v} represents an edge connecting node u and node v.
 *
 * Visual Representation of the Graph:
 *
 * (0)
 * /   \
 * /     \
 * (1)-----(2)
 * /  \    /
 * /    \  /
 * (3)-----(4)-----(5)
 *
 * It has 6 nodes (numbered 0 to 5) and 7 edges.
 */
namespace graph_data {

// Total number of nodes in the graph
const int num_nodes = 6;

// Edge list representation of the graph
const std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3},
                                                {1, 4}, {3, 4}, {4, 5}};
const std::vector<std::pair<int, int>> edges1 = {
    {0, 1}, {0, 2}, {1, 3}, {2, 4}, {2, 5}};

} // namespace graph_data

class Graph {
private:
  void dfsHelper(const std::vector<std::vector<int>> &graph,
                 std::vector<int> &dfs, std::vector<bool> &vis, int i);
  bool detectCycleHelper(const std::vector<std::vector<int>> &graph,
                         std::vector<bool> &vis, int curr, int parent);

public:
  std::vector<int> bfs(std::vector<std::vector<int>> &graph);
  std::vector<int> dfs(std::vector<std::vector<int>> &graph);
  bool detectCycle(std::vector<std::vector<int>> &graph);
};

#endif
