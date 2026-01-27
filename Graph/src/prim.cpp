#include <algorithm>
#include <cassert>

#include "../include/graph.hpp"

// IMPORTANT:
// time - O(E * log(E))
// space - O(V + E)

std::pair<std::vector<std::pair<int, int>>, int> Graph::prim_min_spanning_tree(
    int V, const std::vector<std::vector<int>>& edges) {
  std::vector<uint8_t> vis(V);
  std::vector<std::pair<int, int>> mst;
  std::vector<std::vector<std::pair<int, int>>> graph(V);
  int minSum = 0;

  for (const auto& edge : edges) {
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
  }

  // weight, node, parent
  std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;
  pq.push({0, 0, -1});

  while (!pq.empty()) {
    auto [weight, node, parent] = pq.top();
    pq.pop();

    if (vis[node]) continue;

    vis[node] = 1;
    mst.push_back({node, parent});
    minSum += weight;

    for (const auto& [neighor, w] : graph[node]) {
      if (!vis[neighor]) pq.push({w, neighor, node});
    }
  }

  mst.erase(mst.begin());  // erase {0, -1}
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

    auto result = g.prim_min_spanning_tree(V, edges);

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

    auto result = g.prim_min_spanning_tree(V, edges);

    std::vector<std::pair<int, int>> expectedEdges = {{0, 1}, {1, 2}, {0, 3}, {1, 4}};
    int expectedSum = 16;

    assert(sameEdges(result.first, expectedEdges));
    assert(result.second == expectedSum);

    std::cout << "Test Case 2 passed\n";
  }

  // ---------- 🧪 Test Case 3: Graph already a tree ----------
  {
    int V = 4;
    std::vector<std::vector<int>> edges = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}};

    auto result = g.prim_min_spanning_tree(V, edges);

    std::vector<std::pair<int, int>> expectedEdges = {{0, 1}, {1, 2}, {2, 3}};
    int expectedSum = 6;

    assert(sameEdges(result.first, expectedEdges));
    assert(result.second == expectedSum);

    std::cout << "Test Case 3 passed\n";
  }

  return 0;
}
