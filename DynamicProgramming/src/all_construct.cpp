#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// IMPORTANT:
// Time  : O(n^m)
// Space : O(m)
std::vector<std::vector<std::string>> allConstruct(
    std::string str, const std::vector<std::string>& strs,
    std::unordered_map<std::string, std::vector<std::vector<std::string>>>& memo) {
  if (str.empty()) return {{}};

  if (memo.count(str)) return memo[str];

  std::vector<std::vector<std::string>> res;

  for (auto s : strs) {
    if (str.compare(0, s.size(), s) == 0) {
      auto vec = allConstruct(str.substr(s.size()), strs, memo);
      for (auto way : vec) {
        std::vector<std::string> newWay;
        newWay.push_back(s);
        newWay.insert(newWay.end(), way.begin(), way.end());
        res.push_back(newWay);
      }
    }
  }

  return memo[str] = res;
}

std::vector<std::vector<std::string>> allConstructDp(std::string str, const std::vector<std::string>& strs) {
  // std::vector<std::vector<std::string>> ans;
  // std::vector<std::string> vec;
  std::unordered_map<std::string, std::vector<std::vector<std::string>>> memo;
  return allConstruct(str, strs, memo);
}

using namespace std;
bool equal2D(vector<vector<string>> a, vector<std::vector<string>> b) {
  auto normalize = [](vector<vector<string>>& v) {
    for (auto& x : v) sort(x.begin(), x.end());
    sort(v.begin(), v.end());
  };
  normalize(a);
  normalize(b);
  return a == b;
}
int main() {
  {
    auto out = allConstructDp("abcdef", {"ab", "abc", "cd", "def", "abcd"});
    std::vector<std::vector<std::string>> expected = {{"abc", "def"}};
    assert(equal2D(out, expected));
  }

  {
    auto out = allConstructDp("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"});
    assert(out.empty());
  }

  {
    auto out = allConstructDp("", {"cat", "dog"});
    vector<vector<string>> expected = {{}};
    assert(out == expected);
  }

  {
    auto out = allConstructDp("purple", {"purp", "p", "ur", "le", "purpl"});

    vector<vector<string>> expected = {{"purp", "le"}, {"p", "ur", "p", "le"}};
    assert(equal2D(out, expected));
  }

  {
    auto out = allConstructDp("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"});
    assert(!out.empty());
  }

  {
    auto out = allConstructDp("eeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"});
    assert(out.empty());
  }

  cout << "\033[32mAll test cases passed!\033[0m\n";
}
