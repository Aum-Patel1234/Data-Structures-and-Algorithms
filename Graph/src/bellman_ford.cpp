#include <cassert>
#include <climits>
#include <vector>

#include "../include/graph.hpp"

// NOTE: bellmanFord is used to find the shortest path in the graph
// 1. it works for DG(directed graph)
// 2. helps to detect negative cycles
// Steps:
//    1. Relax all the edges N-1 times sequentially
//    2. if dist relaxed for Nth time return {-1}
// Time Complexity: O(V*E)
// Space Complexity:  O(V)
//
// IMPORTANT:
// 1.Why bellmanFord takes N-1 iterations ?
// -  Shortest path can have at most (n-1) edges in a graph with n vertices
//    Hence, relaxing all edges (n-1) times ensures correct shortest distances
// 2. how to detect negative cycles ?
// -  Max it takes is N-1 so if dist array is updated at Nth time means there is a negative cycle.

// edges = [u,v,w]
std::vector<int> Graph::bellmanFord(int V, const std::vector<std::vector<int>>& edges, int src) {
  const long long INF = 1e18;
  std::vector<long long> dist(V, INF);
  dist[src] = 0;

  for (int i = 0; i < V - 1; ++i) {
    for (const auto& edge : edges) {
      const int &u = edge[0], v = edge[1], w = edge[2];
      if (dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  for (const auto& edge : edges) {
    const int &u = edge[0], v = edge[1], w = edge[2];
    if (dist[u] != INF && dist[u] + w < dist[v]) {
      return {-1};
    }
  }

  std::vector<int> ans(V);
  for (int i = 0; i < V; ++i) {
    ans[i] = (dist[i] == INF) ? 100000000 : dist[i];
  }

  return ans;
}

int main() {
  Graph g;

  // ---------- 🧪 Test Case 1: Normal graph ----------
  {
    int V = 5, src = 0;
    std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 1}};

    std::vector<int> expected = {0, 2, 3, 9, 6};
    assert(g.bellmanFord(V, edges, src) == expected);
  }

  // ---------- 🧪 Test Case 2: Graph with unreachable nodes ----------
  {
    int V = 6, src = 0;
    std::vector<std::vector<int>> edges = {
        {0, 1, 5}, {1, 2, 3}, {2, 3, 1}  // nodes 4 and 5 unreachable
    };

    std::vector<int> expected = {0, 5, 8, 9, 100000000, 100000000};
    assert(g.bellmanFord(V, edges, src) == expected);
  }

  // ---------- 🧪 Test Case 3: Negative cycle reachable from source ----------
  {
    int V = 3, src = 0;
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, -1}, {2, 1, -1}};

    std::vector<int> expected = {-1};
    assert(g.bellmanFord(V, edges, src) == expected);
  }

  return 0;
}
