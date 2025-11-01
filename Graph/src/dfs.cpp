#include "../include/graph.hpp"

std::vector<int> Graph::dfs(std::vector<std::vector<int>>& graph) {
  std::vector<int> dfs;
  std::vector<bool> vis(graph_data::num_nodes, false);
  for (int i = 0; i < graph_data::num_nodes; i++) {
    if (!vis[i]) dfsHelper(graph, dfs, vis, i);
  }
  return dfs;
}

void Graph::dfsHelper(const std::vector<std::vector<int>>& graph, std::vector<int>& dfs, std::vector<bool>& vis,
                      int idx) {
  vis[idx] = true;
  dfs.emplace_back(idx);
  for (int neighbor : graph[idx]) {
    if (!vis[neighbor]) dfsHelper(graph, dfs, vis, neighbor);
  }
}

int main() {
  std::vector<std::vector<int>> graph(graph_data::num_nodes);
  for (auto& edge : graph_data::edges) {
    graph[edge.first].emplace_back(edge.second);
    graph[edge.second].emplace_back(edge.first);
  }
  // int node_id = 0;
  // for (const auto &neighbors : graph) {
  //   std::cout << "Node " << node_id << " -> ";
  //   for (int neighbor : neighbors) {
  //     std::cout << neighbor << " ";
  //   }
  //   std::cout << std::endl;
  //   node_id++;
  // }
  Graph g;
  std::vector<int> result = g.dfs(graph);

  std::cout << "DFS Traversal: ";
  for (int node : result) {
    std::cout << node << " ";
  }
  std::cout << std::endl;

  return 0;
}
