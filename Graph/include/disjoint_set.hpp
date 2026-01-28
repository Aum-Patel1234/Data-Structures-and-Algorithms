#pragma once

#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

class DisjointSet {
 private:
  int n;
  std::vector<int> rank, parent, size;

 public:
  explicit DisjointSet(int n);

  int findParent(int node);

  void unionByRank(int u, int v);
  void unionBySize(int u, int v);
};
