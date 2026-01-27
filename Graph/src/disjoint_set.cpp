#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <vector>

#include "../include/graph.hpp"

class DisjointSet {
 private:
  int n;
  std::vector<int> rank, parent;

 public:
  DisjointSet(int n) : n(n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; ++i) parent[i] = i;
  }

  int findParent(int node) {
    if (node < 0 || node > n) throw std::runtime_error("findParent: invalid node index.");

    if (parent[node] == node) return node;

    parent[node] = findParent(parent[node]);
    return parent[node];
  }

  void unionByRank(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    if (pu == pv) return;

    if (rank[pu] > rank[pv])
      parent[pv] = pu;
    else if (rank[pu] < rank[pv])
      parent[pu] = pv;
    else {
      parent[pv] = pu;
      rank[pu]++;
    }
  }
};

using namespace std;

int main() {
  // ---------- 🧪 Test Case 1: Single element ----------
  {
    DisjointSet ds(1);
    assert(ds.findParent(1) == 1);
  }

  // ---------- 🧪 Test Case 2: Simple union ----------
  {
    DisjointSet ds(5);

    ds.unionByRank(1, 2);
    ds.unionByRank(3, 4);

    assert(ds.findParent(1) == ds.findParent(2));
    assert(ds.findParent(3) == ds.findParent(4));
    assert(ds.findParent(1) != ds.findParent(3));
  }

  // ---------- 🧪 Test Case 3: Chain unions ----------
  {
    DisjointSet ds(6);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(3, 4);

    int root = ds.findParent(1);
    assert(ds.findParent(2) == root);
    assert(ds.findParent(3) == root);
    assert(ds.findParent(4) == root);
  }

  // ---------- 🧪 Test Case 4: Union by rank correctness ----------
  {
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(3, 4);
    ds.unionByRank(1, 3);  // merge two equal-rank trees

    int root = ds.findParent(1);
    assert(ds.findParent(2) == root);
    assert(ds.findParent(3) == root);
    assert(ds.findParent(4) == root);
  }

  // ---------- 🧪 Test Case 5: Redundant union ----------
  {
    DisjointSet ds(4);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(1, 3);  // already connected

    int root = ds.findParent(1);
    assert(ds.findParent(2) == root);
    assert(ds.findParent(3) == root);
  }

  // ---------- 🧪 Test Case 6: Invalid node ----------
  {
    DisjointSet ds(3);
    try {
      ds.findParent(10);
      assert(false);  // should not reach here
    } catch (const runtime_error&) {
      assert(true);
    }
  }

  // custom
  {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // assert(ds.findParent(3) == ds.findParent(7)); // will fail
    ds.unionByRank(3, 7);
    assert(ds.findParent(3) == ds.findParent(7));
  }
  // will fail
  cout << "All Disjoint Set tests passed successfully!\n";
  return 0;
}
