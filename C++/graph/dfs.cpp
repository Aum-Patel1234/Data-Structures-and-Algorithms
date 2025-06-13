#include "make_graph/make_graph.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void helper(vector<vector<int>> &adj, vector<int> &dfs, bool vis[],
              int curr) {
    dfs.push_back(curr);
    vis[curr] = true;

    for (auto node : adj.at(curr)) {
      if (!vis[node]) {
        helper(adj, dfs, vis, node);
      }
    }
  }

public:
  vector<int> dfs(vector<vector<int>> &adj) {
    bool vis[adj.size()]; //  = {false};
    vector<int> dfs;
    helper(adj, dfs, vis, 0);
    return dfs;
  }
};

int main() {
  Solution s;
  vector<vector<int>> adj = createExampleGraph();
  vector<int> result = s.dfs(adj);

  cout << "DFS Traversal: ";
  for (int node : result) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
