#include "../include/disjoint_set.hpp"

DisjointSet::DisjointSet(int n) : n(n) {
  rank.resize(n + 1, 0);
  size.resize(n + 1, 1);
  parent.resize(n + 1);
  for (int i = 0; i <= n; ++i) parent[i] = i;
}

int DisjointSet::findParent(int node) {
  if (node < 0 || node > n) throw std::runtime_error("findParent: invalid node index.");

  if (parent[node] == node) return node;

  parent[node] = findParent(parent[node]);
  return parent[node];
}

void DisjointSet::unionByRank(int u, int v) {
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

void DisjointSet::unionBySize(int u, int v) {
  int pu = findParent(u), pv = findParent(v);
  if (pu == pv) return;

  int size_pu = size[pu], size_pv = size[pv];

  if (size_pu > size_pv) {
    size[pu] += size_pv;
    parent[pv] = pu;
  } else {
    size[pv] += size_pu;
    parent[pu] = pv;
  }
}

// using namespace std;

// int main() {
//   // ---------- Test Case 1: Single element (Rank) ----------
//   {
//     DisjointSet ds(1);
//     assert(ds.findParent(1) == 1);
//   }
//
//   // ---------- Test Case 2: Simple union (Rank) ----------
//   {
//     DisjointSet ds(5);
//
//     ds.unionByRank(1, 2);
//     ds.unionByRank(3, 4);
//
//     assert(ds.findParent(1) == ds.findParent(2));
//     assert(ds.findParent(3) == ds.findParent(4));
//     assert(ds.findParent(1) != ds.findParent(3));
//   }
//
//   // ---------- Test Case 3: Chain unions (Rank) ----------
//   {
//     DisjointSet ds(6);
//
//     ds.unionByRank(1, 2);
//     ds.unionByRank(2, 3);
//     ds.unionByRank(3, 4);
//
//     int root = ds.findParent(1);
//     assert(ds.findParent(2) == root);
//     assert(ds.findParent(3) == root);
//     assert(ds.findParent(4) == root);
//   }
//
//   // ---------- Test Case 4: Merge equal-rank trees ----------
//   {
//     DisjointSet ds(7);
//
//     ds.unionByRank(1, 2);
//     ds.unionByRank(3, 4);
//     ds.unionByRank(1, 3);
//
//     int root = ds.findParent(1);
//     assert(ds.findParent(2) == root);
//     assert(ds.findParent(3) == root);
//     assert(ds.findParent(4) == root);
//   }
//
//   // ---------- Test Case 5: Simple union (Size) ----------
//   {
//     DisjointSet ds(5);
//
//     ds.unionBySize(1, 2);
//     ds.unionBySize(3, 4);
//
//     assert(ds.findParent(1) == ds.findParent(2));
//     assert(ds.findParent(3) == ds.findParent(4));
//     assert(ds.findParent(1) != ds.findParent(3));
//   }
//
//   // ---------- Test Case 6: Chain unions (Size) ----------
//   {
//     DisjointSet ds(6);
//
//     ds.unionBySize(1, 2);
//     ds.unionBySize(2, 3);
//     ds.unionBySize(3, 4);
//
//     int root = ds.findParent(1);
//     assert(ds.findParent(2) == root);
//     assert(ds.findParent(3) == root);
//     assert(ds.findParent(4) == root);
//   }
//
//   // ---------- Test Case 7: Large set merge (Size) ----------
//   {
//     DisjointSet ds(7);
//
//     ds.unionBySize(1, 2);
//     ds.unionBySize(2, 3);
//     ds.unionBySize(4, 5);
//     ds.unionBySize(6, 7);
//     ds.unionBySize(5, 6);
//
//     assert(ds.findParent(1) == ds.findParent(3));
//     assert(ds.findParent(4) == ds.findParent(7));
//     assert(ds.findParent(3) != ds.findParent(7));
//
//     ds.unionBySize(3, 7);
//     assert(ds.findParent(3) == ds.findParent(7));
//   }
//
//   // ---------- Test Case 8: Invalid node ----------
//   {
//     DisjointSet ds(3);
//     try {
//       ds.findParent(10);
//       assert(false);
//     } catch (const std::runtime_error&) {
//       assert(true);
//     }
//   }
//
//   std::cout << "All Disjoint Set tests (Rank + Size) passed successfully!\n";
//   return 0;
// }
