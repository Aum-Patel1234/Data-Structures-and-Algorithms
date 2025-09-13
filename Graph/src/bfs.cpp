#include "../include/graph.hpp"
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> Graph::bfs(std::vector<std::vector<int>> &graph) {
  std::queue<int> queue;
  std::vector<int> bfs;
  std::vector<bool> vis(graph_data::num_nodes, false);
  for (int i = 0; i < graph_data::num_nodes; i++) {
    if (vis[i])
      continue;
    vis[i] = true;
    queue.push(i);
    while (!queue.empty()) {
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        int node = queue.front();
        bfs.emplace_back(node);
        queue.pop();
        for (int neighbor : graph[node]) {
          if (!vis[neighbor]) {
            vis[neighbor] = true;
            queue.push(neighbor);
          }
        }
      }
    }
  }
  return bfs;
}

int main() {
  std::vector<std::vector<int>> graph(graph_data::num_nodes);
  for (auto &edge : graph_data::edges) {
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
  std::vector<int> result = g.bfs(graph);

  std::cout << "BFS Traversal: ";
  for (int node : result) {
    std::cout << node << " ";
  }
  std::cout << std::endl;

  return 0;
}
