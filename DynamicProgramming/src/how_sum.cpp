#include <cassert>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

// NOTE: Brute force: n = size of arr, t = depth of tree, m = target
// Time  : O(n^m * m)     // exponential recursion + vector copy
// Space : O(m) stack
//
// IMPORTANT:
// Time  : O(n * m^2)
// Space : O(m^2)
std::vector<int> howSum(const std::vector<int>& arr, int target, std::unordered_map<int, std::vector<int>>& memo) {
  if (target <= 0) return {};
  if (memo.count(target)) return memo[target];

  for (int num : arr) {
    auto vec = howSum(arr, target - num, memo);

    if (target - num == 0 || !vec.empty()) {
      vec.push_back(num);
      return memo[target] = vec;
    }
  }

  return memo[target] = {};
}

std::vector<int> howSum(const std::vector<int>& arr, int target) {
  std::unordered_map<int, std::vector<int>> memo;
  return howSum(arr, target, memo);
}

void printVec(const std::vector<int>& v) {
  std::cout << "[ ";
  for (int x : v) std::cout << x << " ";
  std::cout << "]\n";
}
int main() {
  auto sumVec = [](const std::vector<int>& v) { return std::accumulate(v.begin(), v.end(), 0); };

  // possible cases
  auto r1 = howSum({2, 3}, 7);
  assert(!r1.empty() && sumVec(r1) == 7);
  printVec(r1);

  auto r2 = howSum({5, 3, 4, 7}, 7);
  assert(!r2.empty() && sumVec(r2) == 7);
  printVec(r2);

  auto r3 = howSum({2, 3, 5}, 8);
  assert(!r3.empty() && sumVec(r3) == 8);
  printVec(r3);

  auto r4 = howSum({3, 34, 4, 12, 5, 2}, 9);
  assert(!r4.empty() && sumVec(r4) == 9);
  printVec(r4);

  auto r5 = howSum({3, 34, 4, 12, 5, 2}, 30);
  assert(!r5.empty() && sumVec(r5) == 30);
  printVec(r5);

  // impossible cases
  assert(howSum({2, 4}, 7).empty());
  assert(howSum({7, 14}, 300).empty());

  std::cout << "\033[32mAll test cases passed!\033[0m\n";

  return 0;
}
