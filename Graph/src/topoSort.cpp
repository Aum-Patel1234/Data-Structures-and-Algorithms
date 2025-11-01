#include "../include/graph.hpp"

/*
 NOTE: Topological Sort
 Linear ordereing of vertices such that if there is and edge between u & v,
 u appears before v in that ordereing
 Time   : O(V+E)
 Space  : O(V)


 IMPORTANT: Works only on DAG(Directed Acyclic Graph) becuase:
  1. let say an  edge beteen 1 and 2 so 1->2 and 2->1 in undirected graph
      which does not make sense for topo sort.
  2. 1->2->3->1 : here 1->3 and 3->1 so does not work
*/

void Graph::topoSortDFS(std::vector<std::vector<int>>& graph, std::vector<bool>& vis, std::stack<int>& stk, int i) {
  vis[i] = true;

  for (int& neighbor : graph[i]) {
    if (!vis[neighbor]) topoSortDFS(graph, vis, stk, neighbor);
  }

  stk.push(i);
}

std::vector<int> Graph::topoSort(std::vector<std::vector<int>>& graph) {
  const int V = graph_data::num_nodes;
  std::stack<int> stk;
  std::vector<bool> vis(V, false);

  for (int i = 0; i < V; i++) {
    if (!vis[i]) topoSortDFS(graph, vis, stk, i);
  }

  std::vector<int> topologicalSort(stk.size());
  int i = 0;
  while (!stk.empty()) {
    topologicalSort[i++] = stk.top();
    stk.pop();
  }
  return topologicalSort;
}

int main() {
  auto& edges = graph_data::edgesDAG;

  std::vector<std::vector<int>> graph(graph_data::num_nodes);
  for (auto& edge : edges) graph[edge.first].push_back(edge.second);

  Graph g;
  std::vector<int> sorted = g.topoSort(graph);
  std::cout << "Topological Sort: ";
  for (int& x : sorted) std::cout << x << " ";
  std::cout << "\n";

  return 0;
}
