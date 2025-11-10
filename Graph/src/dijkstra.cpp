#include <climits>
#include <queue>
#include <utility>
#include <vector>

#include "../include/graph.hpp"

std::vector<int> Graph::dijkstra(int V, const std::vector<std::vector<int>>& edges, int src) {
  std::vector<int> minDist(V, INT_MAX);
  std::vector<std::vector<std::pair<int, int>>> graph(V);

  for (auto& edge : edges) {
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
  }

  // distance, node
  auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
  };
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

  pq.push({0, src});
  minDist[src] = 0;

  while (!pq.empty()) {
    auto [dist, node] = pq.top();
    pq.pop();

    for (auto& edge : graph[node]) {
      if (dist + edge.second < minDist[edge.first]) {
        minDist[edge.first] = dist + edge.second;
        pq.push({minDist[edge.first], edge.first});
      }
    }
  }

  return minDist;
}

int main() {
  Graph g;
  // ---------- 🧪 Test Case 1: Basic connected graph ----------
  {
    const std::vector<std::vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}, {2, 3, 5}};
    int V = 4;
    int src = 0;
    auto minDist = g.dijkstra(V, edges, src);
    std::cout << "Test Case 1:\n";
    for (int i = 0; i < V; i++) std::cout << "Distance from " << src << " to " << i << " = " << minDist[i] << "\n";
    std::cout << "\n";
  }

  // ---------- 🧪 Test Case 2: Disconnected graph ----------
  {
    const std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 5}, {1, 2, 1}, {3, 4, 7}};
    int V = 5;
    int src = 0;
    auto minDist = g.dijkstra(V, edges, src);
    std::cout << "Test Case 2:\n";
    for (int i = 0; i < V; i++) std::cout << "Distance from " << src << " to " << i << " = " << minDist[i] << "\n";
    std::cout << "\n";
  }

  // ---------- 🧪 Test Case 3: Multiple equal-weight paths + isolated node ----------
  {
    const std::vector<std::vector<int>> edges = {{0, 1, 3}, {0, 2, 3}, {1, 3, 2}, {2, 3, 2}, {3, 4, 1}};
    int V = 6;  // node 5 is isolated
    int src = 0;
    auto minDist = g.dijkstra(V, edges, src);
    std::cout << "Test Case 3:\n";
    for (int i = 0; i < V; i++) std::cout << "Distance from " << src << " to " << i << " = " << minDist[i] << "\n";
    std::cout << "\n";
  }
  // Test 1 → [0, 3, 1, 4]
  // Test 2 → [0, 2, 3, INF, INF]
  // Test 3 → [0, 3, 3, 5, 6, INF]

  return 0;
}
