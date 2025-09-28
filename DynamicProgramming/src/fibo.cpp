#include <iostream>
#include <unordered_map>

// NOTE:
// time - O(2^n)
// space - O(n)
int fiboBruteForce(int n) {
  if (n <= 2)
    return 1;
  return fiboBruteForce(n - 1) + fiboBruteForce(n - 2);
}

// IMPORTANT:
// Time - O(2n) -> O(n)
// Space - O(n)
long fiboDP(int n, std::unordered_map<long, long> &memo) {
  if (memo.find(n) != memo.end())
    return memo[n];
  if (n <= 2)
    return 1;
  memo[n] = fiboDP(n - 1, memo) + fiboDP(n - 2, memo);
  return memo[n];
}

int main() {
  std::cout << "Fibo using fiboBruteForce for n=8 = " << fiboBruteForce(8)
            << std::endl;

  std::unordered_map<long, long> memo;
  std::cout << "Fibo using Dynamic Programming (Memoization)  for (n=50)  = "
            << fiboDP(50, memo) << std::endl;
  return 0;
}
