#include <algorithm>
#include <utility>

#include "../include/disjoint_set.hpp"
#include "../include/graph.hpp"

std::pair<std::vector<std::pair<int, int>>, int> Graph::kruskal_min_spanning_tree(
    int V, const std::vector<std::vector<int>>& edges) {
  DisjointSet ds(V);

  std::vector<std::pair<int, int>> mst;
  int minSum = 0;

  auto sortedEdges = edges;
  std::sort(sortedEdges.begin(), sortedEdges.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
    return a[2] < b[2];  // sort by weight
  });

  for (const auto& edge : sortedEdges) {
    int u = edge[0], v = edge[1], w = edge[2];

    if (ds.findParent(u) != ds.findParent(v)) {
      ds.unionByRank(u, v);
      mst.push_back({u, v});
      minSum += w;
    }
  }

  return {mst, minSum};
}

bool sameEdges(std::vector<std::pair<int, int>> a, std::vector<std::pair<int, int>> b) {
  for (auto& e : a) {
    if (e.first > e.second) std::swap(e.first, e.second);
  }
  for (auto& e : b) {
    if (e.first > e.second) std::swap(e.first, e.second);
  }
  std::sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b;
}

int main() {
  Graph g;

  // ---------- 🧪 Test Case 1: Simple graph ----------
  {
    int V = 4;
    std::vector<std::vector<int>> edges = {{0, 1, 5}, {0, 3, 10}, {1, 2, 3}, {2, 3, 1}};

    auto result = g.kruskal_min_spanning_tree(V, edges);

    std::vector<std::pair<int, int>> expectedEdges = {{0, 1}, {1, 2}, {2, 3}};
    int expectedSum = 9;

    assert(sameEdges(result.first, expectedEdges));
    assert(result.second == expectedSum);

    std::cout << "Test Case 1 passed\n";
  }

  // ---------- 🧪 Test Case 2: Fully connected graph ----------
  {
    int V = 5;
    std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, {3, 4, 9}};

    auto result = g.kruskal_min_spanning_tree(V, edges);

    std::vector<std::pair<int, int>> expectedEdges = {{0, 1}, {1, 2}, {1, 4}, {0, 3}};
    int expectedSum = 16;

    assert(sameEdges(result.first, expectedEdges));
    assert(result.second == expectedSum);

    std::cout << "Test Case 2 passed\n";
  }

  // ---------- 🧪 Test Case 3: Graph already a tree ----------
  {
    int V = 4;
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}};

    auto result = g.kruskal_min_spanning_tree(V, edges);

    std::vector<std::pair<int, int>> expectedEdges = {{0, 1}, {1, 2}, {2, 3}};
    int expectedSum = 6;

    assert(sameEdges(result.first, expectedEdges));
    assert(result.second == expectedSum);

    std::cout << "Test Case 3 passed\n";
  }

  std::cout << "All Kruskal MST tests passed successfully!\n";
  return 0;
}
