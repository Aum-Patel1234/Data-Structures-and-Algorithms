#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

// NOTE: Brute force: n = size of arr, m = target
// time - O(n^m)
// space - O(m)
//
// IMPORTANT:
// Time - O(m*n)
// Space - O(m)
bool canSum(const std::vector<int>& arr, int target, std::unordered_map<int, bool>& memo) {
  if (memo.count(target)) return memo[target];
  if (target == 0) return true;
  if (target < 0) return false;

  for (const int num : arr) {
    if (canSum(arr, target - num, memo)) return memo[target] = true;
  }

  return memo[target] = false;
}

bool canSum(const std::vector<int>& arr, int target) {
  std::unordered_map<int, bool> memo;
  return canSum(arr, target, memo);
}

int main() {
  assert(canSum({2, 3}, 7) == true);        // 2+2+3
  assert(canSum({5, 3, 4, 7}, 7) == true);  // direct 7
  assert(canSum({2, 4}, 7) == false);       // impossible
  assert(canSum({2, 3, 5}, 8) == true);     // 3+5
  assert(canSum({7, 14}, 300) == false);    // large impossible case
  assert(canSum({3, 34, 4, 12, 5, 2}, 9) == true);
  assert(canSum({3, 34, 4, 12, 5, 2}, 30) == true);
  std::cout << "\033[32mAll test cases passed!\033[0m\n";

  return 0;
}
