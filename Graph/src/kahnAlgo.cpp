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

std::vector<int> Graph::kahnSort(std::vector<std::vector<int>>& graph) {
  const int V = graph_data::num_nodes;
  std::queue<int> q;
  std::vector<int> indegree(V, 0);
  std::vector<bool> vis(V, false);
  for (int i = 0; i < graph.size(); i++) {
    for (int& edge : graph[i]) indegree[edge]++;
  }

  std::vector<int> sorted;
  for (int i = 0; i < indegree.size(); i++) {
    // std::cout<<i<<" - "<<indegree[i]<<std::endl;
    if (indegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int curr = q.front();
    sorted.push_back(curr);
    q.pop();

    for (int& neighbor : graph[curr]) {
      indegree[neighbor]--;
      if (indegree[neighbor] == 0) q.push(neighbor);
    }
  }

  return sorted;
}

bool Graph::detectCycleDirectedGraphKahnAlgo(std::vector<std::vector<int>>& graph) {
  const int V = graph_data::num_nodes;
  std::vector<int> indegree(V);
  std::queue<int> q;
  int vis = 0;
  for (int i = 0; i < V; i++) {
    for (auto& edge : graph[i]) indegree[edge]++;
  }
  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int curr = q.front();
    vis++;
    q.pop();
    for (auto& neighbor : graph[curr]) {
      indegree[neighbor]--;
      if (indegree[neighbor] == 0) q.push(neighbor);
    }
  }
  std::cout << "The topoSort visited " << vis << " nodes and total are " << V << ".\n";
  return vis < V;
}

int main() {
  auto& edges = graph_data::edgesDAG;

  std::vector<std::vector<int>> graph(graph_data::num_nodes);
  for (auto& edge : edges) graph[edge.first].push_back(edge.second);

  Graph g;
  std::vector<int> sorted = g.kahnSort(graph);
  std::cout << "Kahn Sort(BFS): ";
  for (int& x : sorted) std::cout << x << " ";
  std::cout << "\n\n";

  std::vector<std::vector<int>> directedGraph1(graph_data::num_nodes);
  for (auto& edge : graph_data::edges1) directedGraph1[edge.first].emplace_back(edge.second);

  std::vector<std::vector<int>> directedGraph2(graph_data::num_nodes);
  for (auto& edge : graph_data::edgesDirectedCycle) directedGraph2[edge.first].emplace_back(edge.second);

  bool ans1 = g.detectCycleDirectedGraphKahnAlgo(directedGraph1),
       ans2 = g.detectCycleDirectedGraphKahnAlgo(directedGraph2);
  std::cout << "The directedGraph1 contains cycle - " << ans1 << std::endl;
  std::cout << "The directedGraph2 contains cycle - " << ans2 << std::endl;

  return 0;
}
