#include <climits>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#include "../include/graph.hpp"

// NOTE: it does not work for weight with negative weight
// Time: E log(V)     E - no. of edges, V - no. of nodes

std::vector<int> Graph::dijkstraSet(int V, const std::vector<std::vector<int>>& edges, int src) {
  std::vector<int> ans(V, INT_MAX);
  ans[src] = 0;
  std::set<std::pair<int, int>> set;
  std::vector<std::vector<std::pair<int, int>>> graph(V);

  for (auto& edge : edges) {
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
  }

  set.insert({0, src});
  while (!set.empty()) {
    auto [dist, node] = *set.begin();
    set.erase(set.begin());

    for (auto& [neighbor, edgeDist] : graph[node]) {
      int newDist = edgeDist + dist;
      if (ans[neighbor] > newDist) {
        if (ans[neighbor] != INT_MAX) set.erase({ans[neighbor], neighbor});
        ans[neighbor] = newDist;
        set.insert({newDist, neighbor});
      }
    }
  }

  return ans;
}

std::vector<int> Graph::dijkstraPQ(int V, const std::vector<std::vector<int>>& edges, int src) {
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

std::vector<int> Graph::printShortestPath(int n, int m, std::vector<std::vector<int>>& edges) {
  std::vector<int> minDist(n + 1, INT_MAX), ans;
  std::vector<std::vector<std::pair<int, int>>> graph(n + 1);
  for (auto& edge : edges) {
    graph[edge[0]].push_back({edge[1], edge[2]});
    graph[edge[1]].push_back({edge[0], edge[2]});
  }
  minDist[1] = 0;

  auto cmp = [](const std::pair<std::vector<int>, int>& a, const std::pair<std::vector<int>, int>& b) {
    return a.second > b.second;
  };
  std::priority_queue<std::pair<std::vector<int>, int>, std::vector<std::pair<std::vector<int>, int>>, decltype(cmp)>
      pq(cmp);

  pq.push({{1}, 0});
  while (!pq.empty()) {
    auto [path, dist] = pq.top();
    pq.pop();
    int node = path.back();
    if (node == n) {
      ans = path;
      break;
    }

    for (auto& [neighbor, d] : graph[path.back()]) {
      int newDist = d + dist;
      if (newDist < minDist[neighbor]) {
        std::vector<int> newPath = path;
        newPath.push_back(neighbor);
        minDist[neighbor] = newDist;
        pq.push({newPath, newDist});
      }
    }
  }

  if (ans.empty()) return {-1};
  ans.insert(ans.begin(), minDist[n]);  // prepend minimum distance
  return ans;
}

int main() {
  Graph g;
  // ---------- 🧪 Test Case 1: Basic connected graph ----------
  {
    const std::vector<std::vector<int>> edges = {{0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}, {2, 3, 5}};
    int V = 4;
    int src = 0;
    auto minDist = g.dijkstraPQ(V, edges, src);
    auto m2 = g.dijkstraSet(V, edges, src);
    std::cout << "Test Case 1:\n";
    for (int i = 0; i < V; i++) std::cout << "Distance from " << src << " to " << i << " = " << minDist[i] << "\n";
    for (int i = 0; i < V; i++) std::cout << "Dist from " << src << " to " << i << " = " << m2[i] << "\n";
    std::cout << "\n";
  }

  // ---------- 🧪 Test Case 2: Disconnected graph ----------
  {
    const std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 5}, {1, 2, 1}, {3, 4, 7}};
    int V = 5;
    int src = 0;
    auto minDist = g.dijkstraPQ(V, edges, src);
    auto m2 = g.dijkstraSet(V, edges, src);
    std::cout << "Test Case 2:\n";
    for (int i = 0; i < V; i++) std::cout << "Distance from " << src << " to " << i << " = " << minDist[i] << "\n";
    for (int i = 0; i < V; i++) std::cout << "Dist from " << src << " to " << i << " = " << m2[i] << "\n";
    std::cout << "\n";
  }

  // ---------- 🧪 Test Case 3: Multiple equal-weight paths + isolated node ----------
  {
    const std::vector<std::vector<int>> edges = {{0, 1, 3}, {0, 2, 3}, {1, 3, 2}, {2, 3, 2}, {3, 4, 1}};
    int V = 6;  // node 5 is isolated
    int src = 0;
    auto minDist = g.dijkstraPQ(V, edges, src);
    auto m2 = g.dijkstraSet(V, edges, src);
    std::cout << "Test Case 3:\n";
    for (int i = 0; i < V; i++) std::cout << "Distance from " << src << " to " << i << " = " << minDist[i] << "\n";
    for (int i = 0; i < V; i++) std::cout << "Dist from " << src << " to " << i << " = " << m2[i] << "\n";
    std::cout << "\n";
  }
  // Test 1 → [0, 3, 1, 4]
  // Test 2 → [0, 2, 3, INF, INF]
  // Test 3 → [0, 3, 3, 5, 6, INF]

  // print graph test cases
  // ---------- 🧪 Test Case 1: Simple connected graph ----------
  {
    std::vector<std::vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    int n = 5, m = 6;
    auto result = g.printShortestPath(n, m, edges);
    std::cout << "Test Case 1: Simple connected graph\n";
    std::cout << "Output: ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\nExpected: 5 1 4 3 5\n\n";
  }

  // ---------- 🧪 Test Case 2: No path (disconnected graph) ----------
  {
    std::vector<std::vector<int>> edges = {
        {1, 2, 3}, {2, 3, 4}  // nodes 4 and 5 are disconnected
    };
    int n = 5, m = 2;
    auto result = g.printShortestPath(n, m, edges);
    std::cout << "Test Case 2: Disconnected graph\n";
    std::cout << "Output: ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\nExpected: -1\n\n";
  }

  // ---------- 🧪 Test Case 3: Multiple equal-weight paths + isolated node ----------
  {
    std::vector<std::vector<int>> edges = {
        {1, 2, 3}, {1, 3, 3}, {2, 4, 2}, {3, 4, 2}, {4, 5, 1}  // node 6 isolated
    };
    int n = 5, m = 5;  // ✅ destination is node 5, node 6 is isolated (not needed here)
    auto result = g.printShortestPath(n, m, edges);
    std::cout << "Test Case 3: Multiple equal-weight paths + isolated node\n";
    std::cout << "Output: ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\nExpected: 6 1 2 4 5  (or 6 1 3 4 5)\n\n";
  }

  return 0;
}
