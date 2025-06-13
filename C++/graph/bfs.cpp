#include "make_graph/make_graph.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> bfs(vector<vector<int>> &adj) {
    bool vis[adj.size()];
    std::queue<int> q;
    q.push(0);
    vis[0] = true;
    vector<int> ans;

    while (!q.empty()) {
      int curr = q.front();
      ans.push_back(curr);
      q.pop();

      for (int node : adj.at(curr)) {
        if (!vis[node]) {
          vis[node] = true;
          q.push(node);
        }
      }
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> adj = createExampleGraph();
  vector<int> result = s.bfs(adj);

  cout << "BFS Traversal: ";
  for (int node : result) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
