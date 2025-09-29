#include "../include/graph.hpp"
#include <iostream>
#include <stack>
#include <vector>

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

std::vector<int> Graph::kahnSort(std::vector<std::vector<int>> &graph)
{
  const int V = graph_data::num_nodes;
  std::queue<int> q;
  std::vector<int> indegree(V, 0);
  std::vector<bool> vis(V, false);
  for (int i = 0; i < graph.size(); i++)
  {
    for (int &edge : graph[i])
      indegree[edge]++;
  }

  std::vector<int> sorted;
  for (int i = 0; i < indegree.size(); i++)
  {
    // std::cout<<i<<" - "<<indegree[i]<<std::endl;
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    int curr = q.front();
    sorted.push_back(curr);
    q.pop();

    for (int &neighbor : graph[curr])
    {
      indegree[neighbor]--;
      if (indegree[neighbor] == 0)
        q.push(neighbor);
    }
    graph[curr].erase(graph[curr].begin(), graph[curr].end());
  }

  //   for (int i = 0; i < sorted.size(); i++)
  //   {
  //     std::cout<<sorted[i]<<"\t";
  //   }

  return sorted;
}

int main()
{
  auto &edges = graph_data::edgesDAG;

  std::vector<std::vector<int>> graph(graph_data::num_nodes);
  for (auto &edge : edges)
    graph[edge.first].push_back(edge.second);

  Graph g;
  std::vector<int> sorted = g.kahnSort(graph);
  std::cout << "Kahn Sort(BFS): ";
  for (int &x : sorted)
    std::cout << x << " ";
  std::cout << "\n";

  return 0;
}
