#include "../include/graph.hpp"
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// NOTE: Using DFS
bool Graph::detectCycleDFS(std::vector<std::vector<int>> &graph) {
  std::vector<bool> vis(graph_data::num_nodes, false);
  for (int i = 0; i < graph_data::num_nodes; i++) {
    if (!vis[i] && detectCycleHelper(graph, vis, i, -1))
      return true;
  }
  return false;
}
bool Graph::detectCycleHelper(const std::vector<std::vector<int>> &graph,
                              std::vector<bool> &vis, int curr, int parent) {
  vis[curr] = true;

  for (const int &neighbour : graph[curr]) {
    if (!vis[neighbour]) {
      if (detectCycleHelper(graph, vis, neighbour, curr))
        return true;
    } else if (parent != neighbour)
      return true;
  }
  return false;
}

// NOTE: Using BFS
bool Graph::detectCycleBFS(std::vector<std::vector<int>> &graph) {
  std::queue<std::pair<int, int>> q;
  std::vector<bool> vis(graph_data::num_nodes, false);
  q.push({0, -1});
  vis[0] = true;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      std::pair<int, int> curr = q.front();
      auto [node, parent] = q.front();
      q.pop();
      for (int neighbour : graph[node]) {
        if (!vis[neighbour]) {
          vis[neighbour] = true; // IMPORTANT: this is imp
          q.push({neighbour, node});
        } else if (neighbour != parent)
          return true;
      }
    }
  }
  return false;
}

int main() {
  std::vector<std::vector<int>> graph(graph_data::num_nodes);
  for (auto &edge : graph_data::edges) {
    graph[edge.first].emplace_back(edge.second);
    graph[edge.second].emplace_back(edge.first);
  }
  std::vector<std::vector<int>> graph1(graph_data::num_nodes);
  for (auto &edge : graph_data::edges1) {
    graph[edge.first].emplace_back(edge.second);
    graph[edge.second].emplace_back(edge.first);
  }

  Graph g;
  std::cout << "The graph edges contains cycle (DFS) - "
            << g.detectCycleDFS(graph) << std::endl;
  std::cout << "The graph edges1 contains cycle (DFS) - "
            << g.detectCycleDFS(graph1) << std::endl
            << std::endl;
  std::cout << "The graph edges contains cycle (BFS) -"
            << g.detectCycleBFS(graph) << std::endl;
  std::cout << "The graph edges1 contains cycle (BFS) -"
            << g.detectCycleBFS(graph1) << std::endl;

  return 0;
}
