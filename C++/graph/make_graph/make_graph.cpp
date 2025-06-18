#include "make_graph.h"

// Example graph:
// 0 -- 1 -- 2
// |    |    |
// 6 -- 5 -- 3
//      |
//      4

vector<vector<int>> createExampleGraph() {
  vector<vector<int>> adj = {
      {1, 6},       // Neighbors of node 0
      {0, 2, 5},    // Neighbors of node 1
      {1, 3},       // Neighbors of node 2
      {2, 5},       // Neighbors of node 3
      {5},          // Neighbors of node 4
      {1, 3, 4, 6}, // Neighbors of node 5
      {0, 5}        // Neighbors of node 6
  };

  return adj;
}

// Example graph without a cycle:
// 0 -- 1    3
// |    |
// 4    2

vector<vector<int>> createExampleGraphNoCycle() {
  vector<vector<int>> adj = {
      {1, 4}, // Neighbors of node 0
      {0, 2}, // Neighbors of node 1
      {1},    // Neighbors of node 2
      {},     // Neighbors of node 3 (isolated node)
      {0}     // Neighbors of node 4
  };

  return adj;
}
