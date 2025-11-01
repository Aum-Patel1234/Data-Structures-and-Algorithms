#include "../include/graph.hpp"

std::vector<int> Graph::shortestPathFromSrc(const std::vector<std::vector<int>>& adj, int src) {
  const int V = adj.size();
  std::vector<int> ans(V, INT_MAX);
  std::vector<uint8_t> vis(V);
  std::queue<int> q;
  q.push(src);
  ans[src] = 0;
  while (!q.empty()) {
    int curr = q.front();
    vis[curr] = 1;
    q.pop();

    for (auto& edge : adj[curr]) {
      ans[edge] = std::min(ans[edge], ans[curr] + 1);
      if (!vis[edge]) q.push(edge);
    }
  }

  for (int i = 0; i < V; i++)
    if (ans[i] == INT_MAX) ans[i] = -1;

  return ans;
}

int main() {
  // Given adjacency list
  std::vector<std ::vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};

  int src = 0;
  Graph g;
  std::vector<int> result = g.shortestPathFromSrc(adj, src);

  std::cout << "Shortest distances from source " << src << ":\n";
  for (int i = 0; i < result.size(); i++) {
    std::cout << "Node " << i << ": " << result[i] << "\n";
  }

  return 0;
}
