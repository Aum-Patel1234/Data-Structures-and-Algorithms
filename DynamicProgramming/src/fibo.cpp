#include <sys/types.h>

#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

// NOTE:
// time - O(2^n)
// space - O(n)
int fiboBruteForce(int n) {
  if (n <= 2) return 1;
  return fiboBruteForce(n - 1) + fiboBruteForce(n - 2);
}

// IMPORTANT:
// Time - O(2n) -> O(n)
// Space - O(n)
long fiboDpMemo(int n, std::unordered_map<long, long>& memo) {
  if (memo.find(n) != memo.end()) return memo[n];
  if (n <= 2) return 1;
  memo[n] = fiboDpMemo(n - 1, memo) + fiboDpMemo(n - 2, memo);
  return memo[n];
}

// IMPORTANT:
// Time - O(n)
// Space - O(n)
long fiboDpTabulation(int n) {
  if (n <= 1) return n;

  std::vector<long> tab(n + 1);
  tab[0] = 0;
  tab[1] = 1;
  for (size_t i = 2; i <= n; ++i) tab[i] = tab[i - 1] + tab[i - 2];
  return tab[n];
}

int main() {
  std::cout << "Fibo using fiboBruteForce for n=8 = " << fiboBruteForce(8) << std::endl;

  std::unordered_map<long, long> memo;
  std::cout << "Fibo using Dynamic Programming (Memoization)  for (n=50)  = " << fiboDpMemo(50, memo) << std::endl;
  std::cout << "Fibo using Dynamic Programming (Tabulation)  for (n=8)  = " << fiboDpTabulation(8) << std::endl;
  std::cout << "Fibo using Dynamic Programming (Tabulation)  for (n=50)  = " << fiboDpTabulation(50) << std::endl;
  return 0;
}
