#include <sys/types.h>

#include <cassert>
#include <cstddef>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// Brute force
// Time  : O(2^(m+n))
// Space : O(m+n)
int paths(int i, int j, int m, int n) {
  if (i == m - 1 && j == n - 1) return 1;
  if (i >= m || j >= n) return 0;

  return paths(i + 1, j, m, n) + paths(i, j + 1, m, n);
}
// int uniquePaths(int m, int n) { return paths(0, 0, m, n); }

struct pair_hash {
  size_t operator()(const std::pair<int, int>& p) const {
    // here to differentiate between 1,3 and 3,1
    // but here in gridTraveller problem it does not matter cause both have same ans
    // return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second));
  };
};
// NOTE:
// Time  : O(m*n)
// Space : O(m+n)
unsigned long paths_memo(std::unordered_map<std::pair<int, int>, unsigned long, pair_hash>& memo, int m, int n) {
  if (m == 1 && n == 1) return 1;
  if (m == 0 || n == 0) return 0;
  if (memo.count({m, n})) return memo[{m, n}];

  return memo[{m, n}] = paths_memo(memo, m - 1, n) + paths_memo(memo, m, n - 1);
}

unsigned long paths_tab(int m, int n) {
  std::vector<std::vector<ulong>> tab(m, std::vector<ulong>(n));
  tab[0][0] = 1;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + 1 < m) tab[i + 1][j] += tab[i][j];
      if (j + 1 < n) tab[i][j + 1] += tab[i][j];
    }
  }

  return tab[m - 1][n - 1];
}

unsigned long uniquePaths(int m, int n) {
  std::unordered_map<std::pair<int, int>, unsigned long, pair_hash> memo;
  // return paths_memo(memo, m, n);
  return paths_tab(m, n);
}

int main() {
  assert(uniquePaths(4, 5) == 35);
  assert(uniquePaths(2, 3) == 3);
  assert(uniquePaths(1, 1) == 1);
  assert(uniquePaths(1, 5) == 1);
  assert(uniquePaths(3, 3) == 6);

  assert(uniquePaths(20, 20) == 35345263800UL);
  std::cout << "\033[32mAll test cases passed!\033[0m\n";

  return 0;
}
