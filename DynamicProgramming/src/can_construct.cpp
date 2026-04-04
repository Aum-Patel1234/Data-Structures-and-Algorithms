#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// NOTE: Brute force: n = size of arr, m =size of target string
// Time  : O(n^m * m)     // exponential recursion + vector copy
// Space : O(m) stack
bool canConstruct(std::string str, const std::vector<std::string>& strs) {
  if (str.empty()) return true;
  for (auto s : strs) {
    if (str.compare(0, s.size(), s) == 0) {
      if (canConstruct(str.substr(s.size()), strs)) return true;
    }
  }
  return false;
}

// IMPORTANT:
// Time  : O(n * m^2)
// Space : O(m^2)
bool canConstruct(std::string str, const std::vector<std::string>& strs, std::unordered_map<std::string, bool>& map) {
  if (str.empty()) return true;
  if (map.count(str)) return map[str];

  for (auto s : strs) {
    if (str.compare(0, s.size(), s) == 0) {
      if (canConstruct(str.substr(s.size()), strs, map)) return map[str] = true;
    }
  }
  return map[str] = false;
}

bool canConstructTab(std::string str, const std::vector<std::string>& strs) {}

bool canConstructDp(std::string str, const std::vector<std::string>& strs) {
  std::unordered_map<std::string, bool> map;
  return canConstruct(str, strs, map);
}

int main() {
  assert(canConstructDp("abcdef", {"ab", "abc", "cd", "def", "abcd"}) == true);
  assert(canConstructDp("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) == false);
  assert(canConstructDp("", {"cat", "dog"}) == true);
  assert(canConstructDp("purple", {"purp", "p", "ur", "le", "purpl"}) == true);
  assert(canConstructDp("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) == true);
  assert(canConstructDp("eeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}) == false);
  std::cout << "\033[32mAll test cases passed!\033[0m\n";
}
