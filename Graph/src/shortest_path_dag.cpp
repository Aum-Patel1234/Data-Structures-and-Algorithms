#include "../include/graph.hpp"

void Graph::dfsShortestPathFromSrcDAGhelper(const std::vector<std::vector<std::pair<int, int>>>& adj,
                                            std::vector<uint8_t>& vis, std::stack<int>& stk, int curr) {
  vis[curr] = 1;

  for (auto& neighbor : adj[curr]) {
    if (!vis[neighbor.first]) dfsShortestPathFromSrcDAGhelper(adj, vis, stk, neighbor.first);
  }

  stk.push(curr);
}

std::vector<int> Graph::shortestPathFromSrcDAG(int V, int E, const std::vector<std::vector<int>>& graph) {
  std::vector<std::vector<std::pair<int, int>>> adj(V);
  for (auto& edge : graph) {
    adj[edge[0]].push_back({edge[1], edge[2]});
  }

  std::stack<int> stk;
  std::vector<uint8_t> vis(V);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) dfsShortestPathFromSrcDAGhelper(adj, vis, stk, i);
  }

  std::vector<int> ans(V, INT_MAX);
  ans[0] = 0;
  while (!stk.empty()) {
    int curr = stk.top();
    stk.pop();

    if (ans[curr] != INT_MAX) {  // as it leads to int overflow
      for (auto& neighbor : adj[curr]) {
        auto& [edge, weight] = neighbor;
        ans[edge] = std::min(ans[edge], ans[curr] + weight);
      }
    }
  }

  for (int& val : ans)
    if (val == INT_MAX) val = -1;  // not reachable

  return ans;
}

int main() {
  Graph g;
  auto& edges = graph_data::weightedEdges;
  const int V = 6, E = edges.size();

  std::vector<int> result = g.shortestPathFromSrcDAG(V, E, edges);

  std::cout << "Shortest path from source 0 to all vertices:\n";
  for (int i = 0; i < V; ++i) {
    std::cout << "0 -> " << i << " = " << result[i] << "\n";
  }

  return 0;
}
