#pragma once

#include <climits>
#include <cstdint>
#include <iostream>
#include <queue>
#include <stack>
#ifndef GRAPH_H
#define GRAPH_H
#include <utility>  // Required for std::pair
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
const std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
const std::vector<std::pair<int, int>> edges1 = {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {2, 5}};

const std::vector<std::pair<int, int>> edgesEvenCycle = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},  // square cycle (0-1-2-3-0)
    {2, 4}, {4, 5}                   // chain extension (extra nodes 4 and 5)
};

const std::vector<std::pair<int, int>> edgesDAG = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {2, 5}};

//
// 0 ----- 1
// |       |
// |       |
// 3 ----- 2 ---- 4 ---- 5
const std::vector<std::pair<int, int>> edgesDirectedCycle = {
    {0, 1}, {1, 2}, {2, 0},  // cycle: 0 -> 1 -> 2 -> 0
    {2, 3}, {3, 4},          // chain from the cycle
    {4, 2}                   // another back edge forming a cycle: 2 -> 3 -> 4 -> 2
};

const std::vector<std::vector<int>> weightedEdges = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6},  {1, 2, 2}, {2, 4, 4},
                                                     {2, 5, 2}, {2, 3, 7}, {3, 4, -1}, {4, 5, -2}};

}  // namespace graph_data

class Graph {
 private:
  void dfsHelper(const std::vector<std::vector<int>>& graph, std::vector<int>& dfs, std::vector<bool>& vis, int i);
  void dfsShortestPathFromSrcDAGhelper(const std::vector<std::vector<std::pair<int, int>>>& adj,
                                       std::vector<uint8_t>& vis, std::stack<int>& stk, int curr);
  bool detectCycleHelper(const std::vector<std::vector<int>>& graph, std::vector<bool>& vis, int curr, int parent);
  bool isBipartiteDFSHelper(const std::vector<std::vector<int>>& graph, std::vector<int>& color, int curr,
                            int currentColor);
  bool hasCycleDirectedGraph(const std::vector<std::vector<int>>& graph, std::vector<bool>& vis,
                             std::vector<bool>& pathVis, int curr);
  void topoSortDFS(std::vector<std::vector<int>>& graph, std::vector<bool>& vis, std::stack<int>& stk, int i);

 public:
  std::vector<int> bfs(std::vector<std::vector<int>>& graph);
  std::vector<int> dfs(std::vector<std::vector<int>>& graph);
  std::vector<int> topoSort(std::vector<std::vector<int>>& graph);
  std::vector<int> kahnSort(std::vector<std::vector<int>>& graph);
  std::vector<int> shortestPathFromSrcDAG(int V, int E, const std::vector<std::vector<int>>& edges);
  std::vector<int> shortestPathFromSrc(const std::vector<std::vector<int>>& adj, int src);
  std::vector<int> dijkstraPQ(int V, const std::vector<std::vector<int>>& edges, int src);
  std::vector<int> dijkstraSet(int V, const std::vector<std::vector<int>>& edges, int src);
  std::vector<int> bellmanFord(int V, const std::vector<std::vector<int>>& edges, int src);
  std::vector<std::vector<int>> floydWarshall(int V, const std::vector<std::vector<int>>& edges);
  std::pair<std::vector<std::pair<int, int>>, int> prim_min_spanning_tree(int V,
                                                                          const std::vector<std::vector<int>>& edges);
  std::vector<int> printShortestPath(int n, int m, std::vector<std::vector<int>>& edges);
  bool detectCycleDirectedGraphKahnAlgo(std::vector<std::vector<int>>& graph);
  bool detectCycleDFS(std::vector<std::vector<int>>& graph);
  bool detectCycleBFS(std::vector<std::vector<int>>& graph);
  bool detectCycleDirectedGraph(std::vector<std::vector<int>>& graph);
  bool isBipartiteBFS(std::vector<std::vector<int>>& graph);
  bool isBipartiteDFS(std::vector<std::vector<int>>& graph);
};

#endif
