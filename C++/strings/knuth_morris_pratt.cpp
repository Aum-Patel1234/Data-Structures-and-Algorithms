#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

void printVec(std::vector<int>& vec) {
  std::cout << "Size of vec: " << vec.size() << "\n";
  for (int num : vec) std::cout << num << " ";
  std::cout << "\n\n";
}

std::vector<int> search(std::string& pat, std::string& txt) {
  const size_t n = pat.size(), m = txt.size();
  std::vector<int> pi_table(n, 0);
  std::vector<int> ans;

  // Build Longest prefix-sufix(pi table) lps
  size_t j = 0;
  pi_table[j] = 0;
  for (size_t i = 1; i < n; ++i) {
    while (j > 0 && pat[i] != pat[j]) j = pi_table[j - 1];
    if (pat[i] == pat[j]) j++;
    pi_table[i] = j;
  }

  j = 0;
  for (size_t i = 0; i < m; ++i) {
    while (j > 0 && txt[i] != pat[j]) j = pi_table[j - 1];

    if (txt[i] == pat[j]) j++;

    if (j == n) {
      ans.push_back(i - n + 1);
      j = pi_table[j - 1];
    }
  }

  return ans;
}

int main() {
  {
    std::string txt = "ababcabcab";
    std::string pat = "abc";
    std::vector<int> res = search(pat, txt);
    assert((res == std::vector<int>{2, 5}));
  }

  {
    std::string txt = "aaaaa";
    std::string pat = "aa";
    std::vector<int> res = search(pat, txt);
    assert((res == std::vector<int>{0, 1, 2, 3}));
  }

  {
    std::string txt = "hello";
    std::string pat = "ll";
    std::vector<int> res = search(pat, txt);
    assert((res == std::vector<int>{2}));
  }

  {
    std::string txt = "abcdef";
    std::string pat = "gh";
    std::vector<int> res = search(pat, txt);
    assert(res.empty());
  }

  {
    std::string txt = "a";
    std::string pat = "a";
    std::vector<int> res = search(pat, txt);
    assert((res == std::vector<int>{0}));
  }

  {
    std::string txt = "abc";
    std::string pat = "abcd";
    std::vector<int> res = search(pat, txt);
    assert(res.empty());
  }

  std::cout << "All tests passed!\n";
}
