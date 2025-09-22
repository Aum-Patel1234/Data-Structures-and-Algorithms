#include "../include/graph.hpp"
#include <iostream>
#include <queue>
#include <vector>

// NOTE: Bipartite Graph
// Basic Def:  Color the graph  with 2 colors such that no adjacent
//             nodes have same color
// 1. Linear Graph with no cycle is always Bipartite
// 2. Any Graph with a even cycle length is also Bipartite
//
// IMPORTANT: Any Graph with odd length cycle can never be a Bipartite

bool Graph::isBipartiteBFS(std::vector<std::vector<int>> &graph) {
  const int V = graph_data::num_nodes;
  std::vector<int> color(V, -1);
  std::queue<int> q;
  q.push(0);
  color[0] = 0;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (auto &neighbor : graph[curr]) {
      if (-1 == color[neighbor]) {
        color[neighbor] = !color[curr];
        q.push(neighbor);
      } else if (color[neighbor] == color[curr])
        return false;
    }
  }
  return true;
}

bool Graph::isBipartiteDFSHelper(const std::vector<std::vector<int>> &graph,
                                 std::vector<int> &color, int curr,
                                 int currentColor) {
  color[curr] = currentColor;

  for (auto &neighbor : graph[curr]) {
    if (color[neighbor] == -1) {
      if (!isBipartiteDFSHelper(graph, color, neighbor, !currentColor))
        return false;
    } else if (color[curr] == color[neighbor])
      return false;
  }
  return true;
}

bool Graph::isBipartiteDFS(std::vector<std::vector<int>> &graph) {
  const int V = graph_data::num_nodes;
  std::vector<int> color(V, -1);

  for (int i = 0; i < V; i++) {
    if (color[i] == -1 && !isBipartiteDFSHelper(graph, color, i, 0))
      return false;
  }

  return true;
}

int main() {
  std::vector<std::vector<int>> graph(graph_data::num_nodes);
  for (auto &edge : graph_data::edgesEvenCycle) {
    graph[edge.first].emplace_back(edge.second);
    graph[edge.second].emplace_back(edge.first);
  }
  std::vector<std::vector<int>> graph1(graph_data::num_nodes);
  for (auto &edge : graph_data::edges) {
    graph1[edge.first].emplace_back(edge.second);
    graph1[edge.second].emplace_back(edge.first);
  }

  Graph g;
  std::cout << "The graph even edges is Bipartite (DFS) - "
            << g.isBipartiteDFS(graph) << std::endl;
  std::cout << "The graph is Bipartite (DFS) - " << g.isBipartiteDFS(graph1)
            << std::endl
            << std::endl;
  std::cout << "The graph even edges is Bipartite (BFS) - "
            << g.isBipartiteBFS(graph) << std::endl;
  std::cout << "The graph is Bipartite (BFS) - " << g.isBipartiteBFS(graph1)
            << std::endl;

  return 0;
}
