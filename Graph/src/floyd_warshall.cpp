#include <cassert>
#include <climits>
#include <vector>

#include "../include/graph.hpp"

std::vector<std::vector<int>> Graph::floydWarshall(int V, const std::vector<std::vector<int>>& edges) {
  std::vector<std::vector<int>> min_dist(V, std::vector<int>(V, INT_MAX));

  for (auto& edge : edges) min_dist[edge[0]][edge[1]] = edge[2];
  for (int i = 0; i < V; ++i) min_dist[i][i] = 0;

  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      for (int k = 0; k < V; ++k) {
        if (min_dist[j][i] == INT_MAX || min_dist[i][k] == INT_MAX) continue;

        min_dist[j][k] = std::min(min_dist[j][k], min_dist[j][i] + min_dist[i][k]);  // j->i>k
      }
    }
  }

  for (int i = 0; i < V; ++i) {
    if (min_dist[i][i] < 0) return {{-1}};
  }

  return min_dist;
}

int main() {
  Graph g;

  // ---------- 🧪 Test Case 1: Simple graph ----------
  {
    int V = 4;
    std::vector<std::vector<int>> edges = {{0, 1, 5}, {0, 3, 10}, {1, 2, 3}, {2, 3, 1}};

    auto result = g.floydWarshall(V, edges);

    std::vector<std::vector<int>> expected = {
        {0, 5, 8, 9}, {INT_MAX, 0, 3, 4}, {INT_MAX, INT_MAX, 0, 1}, {INT_MAX, INT_MAX, INT_MAX, 0}};

    assert(result == expected);
    std::cout << "Test Case 1 passed\n";
  }

  // ---------- 🧪 Test Case 2: Graph with negative edges (no cycle) ----------
  {
    int V = 3;
    std::vector<std::vector<int>> edges = {{0, 1, 4}, {0, 2, 11}, {1, 2, -5}};

    auto result = g.floydWarshall(V, edges);

    std::vector<std::vector<int>> expected = {{0, 4, -1}, {INT_MAX, 0, -5}, {INT_MAX, INT_MAX, 0}};

    assert(result == expected);
    std::cout << "Test Case 2 passed\n";
  }

  // ---------- 🧪 Test Case 3: Negative cycle ----------
  {
    int V = 3;
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, -1}, {2, 1, -1}};

    auto result = g.floydWarshall(V, edges);

    std::vector<std::vector<int>> expected = {{-1}};
    assert(result == expected);

    std::cout << "Test Case 3 passed (negative cycle detected)\n";
  }

  return 0;
}
