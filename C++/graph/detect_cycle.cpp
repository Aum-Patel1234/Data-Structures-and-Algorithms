#include "make_graph/make_graph.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class DetectCycle {
public:
  /*
  Time Complexity:
  O(V + E)
  - V: Number of vertices.
  - E: Number of edges.
  - Why? Every node is visited once, and every edge is considered once (in
  undirected graph).

  Space Complexity:
  O(V)
  - Visited array: O(V)
  - Queue: At most O(V) nodes can be in the queue.
  - No extra adjacency list storage since we use the input graph directly.
  */
  bool isCycleBfs(int V, vector<vector<int>> &edges) {
    bool vis[V];
    queue<pair<int, int>> q;

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        q.push({-1, i});
        vis[i] = true;
        while (!q.empty()) {
          int parent = q.front().first, child = q.front().second;
          q.pop();

          for (int num : edges[child]) {
            if (!vis[num]) {
              q.push({child, num});
              vis[num] = true;
            } else if (parent != num) {
              return true;
            }
          }
        }
      }
    }

    return false;
  }
  /*
    Time Complexity: O(V + E)
    - DFS traversal visits each vertex once: O(V)
    - Each edge is traversed at most twice in an undirected graph: O(E)
    So, total time: O(V + E)

    Space Complexity: O(V)
    - Visited array: O(V)
    - Recursive stack can go up to depth O(V) in worst case
    So, total space: O(V)
    */
  bool isCycleDfs(int V, vector<vector<int>> &edges) {
    bool vis[V];

    for (int i = 0; i < V; i++) {
      if (!vis[i]) {
        if (helper(i, -1, edges, vis))
          return true;
      }
    }

    return false;
  }

  bool helper(int curr, int parent, vector<vector<int>> &edges, bool vis[]) {
    vis[curr] = true;

    for (int edge : edges[curr]) {
      if (!vis[edge]) {
        if (helper(edge, curr, edges, vis))
          return true;
      } else if (edge != parent) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  DetectCycle dc;

  vector<vector<int>> edges = createExampleGraph(); // From make_graph.h

  int V = 7; // Total number of nodes (0 to 6)

  if (dc.isCycleBfs(V, edges)) {
    cout << "Cycle detected in the graph. - BFS" << endl;
  } else {
    cout << "No cycle detected in the graph." << endl;
  }
  if (dc.isCycleDfs(V, edges)) {
    cout << "Cycle detected in the graph. - DFS" << endl;
  } else {
    cout << "No cycle detected in the graph. - DFS" << endl;
  }

  edges = createExampleGraphNoCycle();
  V = 5;

  if (dc.isCycleBfs(V, edges)) {
    cout << "Cycle detected in the graph." << endl;
  } else {
    cout << "No cycle detected in the graph." << endl;
  }
  if (dc.isCycleDfs(V, edges)) {
    cout << "Cycle detected in the graph. - DFS" << endl;
  } else {
    cout << "No cycle detected in the graph. - DFS" << endl;
  }

  return 0;
}
