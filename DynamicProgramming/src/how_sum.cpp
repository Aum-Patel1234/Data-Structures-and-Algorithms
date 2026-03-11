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

std::vector<int> howSumTab(const std::vector<int>& arr, int target) {
  std::vector<std::vector<int>> tab(target + 1);

  for (int i = 0; i <= target; ++i) {
    if (i != 0 && tab[i].empty()) continue;

    for (int num : arr) {
      if (i + num <= target) {
        tab[i + num] = tab[i];
        tab[i + num].push_back(num);
      }
    }
  }

  return tab[target];
}

std::vector<int> howSum(const std::vector<int>& arr, int target) {
  // std::unordered_map<int, std::vector<int>> memo;
  // return howSum(arr, target, memo);
  return howSumTab(arr, target);
}

std::vector<int> bestSum(const std::vector<int>& arr, int target) {
  std::vector<std::vector<int>> tab(target + 1);

  for (int i = 0; i <= target; ++i) {
    if (i != 0 && tab[i].empty()) continue;

    for (auto num : arr) {
      if (i + num <= target && (tab[i + num].empty() || tab[i].size() + 1 < tab[i + num].size())) {
        tab[i + num] = tab[i];
        tab[i + num].push_back(num);
      }
    }
  }

  return tab[target];
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

  std::cout << "\nBest Sum Test Cases: \n";
  // Best sum
  r1 = bestSum({2, 3, 5}, 8);
  assert(!r1.empty() && sumVec(r1) == 8 && r1.size() == 2);
  printVec(r1);

  r2 = bestSum({1, 4, 5}, 8);
  assert(!r2.empty() && sumVec(r2) == 8 && r2.size() == 2);
  printVec(r2);

  r3 = bestSum({1, 2, 8}, 8);
  assert(!r3.empty() && sumVec(r3) == 8 && r3.size() == 1);
  printVec(r3);

  r4 = bestSum({3, 5}, 7);
  assert(r4.empty());
  printVec(r4);

  r5 = bestSum({7, 14}, 28);
  assert(!r5.empty() && sumVec(r5) == 28 && r5.size() == 2);
  printVec(r5);

  auto r6 = bestSum({2, 3, 5}, 10);
  assert(!r6.empty() && sumVec(r6) == 10 && r6.size() == 2);
  printVec(r6);

  auto r7 = bestSum({1, 3, 5, 25}, 100);
  assert(!r7.empty() && sumVec(r7) == 100 && r7.size() == 4);
  printVec(r7);

  std::cout << "\033[32mAll test cases passed!\033[0m\n";

  return 0;
}
