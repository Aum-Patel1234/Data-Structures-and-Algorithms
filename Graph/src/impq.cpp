#include <bits/stdc++.h>

#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
  std::unordered_set<std::string> s(wordList.begin(), wordList.end());
  if (s.find(endWord) == s.end()) return 0;
  std::queue<std::pair<std::string, uint16_t>> q;
  q.push({beginWord, 1});

  const char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  while (!q.empty()) {
    auto curr = q.front();
    if (curr.first == endWord) return curr.second;
    q.pop();
    s.erase(curr.first);

    for (int i = 0; i < curr.first.length(); i++) {
      auto copy = curr;
      auto& [str, num] = copy;

      for (auto& ch : letters) {
        if (str[i] != ch) {
          str[i] = ch;
          if (s.find(copy.first) != s.end()) {
            q.push({str, num + 1});
            s.erase(str);
          }
        }
      }
    }
  }

  return 0;
}

// first way
std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord,
                                                  std::vector<std::string>& wordList) {
  std::vector<std::vector<std::string>> ans;
  std::unordered_set<std::string> s(wordList.begin(), wordList.end());
  if (s.find(endWord) == s.end()) return ans;

  std::queue<std::vector<std::string>> q;
  std::vector<std::string> used;
  used.push_back(beginWord);
  q.push({beginWord});
  const char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  bool found = false;
  while (!q.empty() && !found) {
    int size = q.size();
    for (auto& w : used) s.erase(w);
    used.clear();

    for (int i = 0; i < size; i++) {
      auto curr = q.front();
      q.pop();
      auto& word = curr.back();
      if (word == endWord) {
        ans.push_back(curr);
        found = true;
        continue;
      }

      for (int j = 0; j < word.size(); j++) {
        auto copy = word;
        for (auto& ch : chars) {
          if (ch == copy[j]) continue;
          copy[j] = ch;
          if (s.find(copy) != s.end()) {
            auto next = curr;
            next.push_back(copy);
            q.push(next);
            used.push_back(copy);
          }
        }
      }
    }
  }

  return ans;
}

// optimal way word ladder 2
void dfs(std::vector<std::vector<std::string>>& ans, const std::unordered_map<std::string, uint16_t>& map,
         const char (&chars)[26], std::vector<std::string>& vec, const std::string& beginWord) {
  std::string curr = vec.back();
  if (curr == beginWord) {
    std::vector<std::string> temp = vec;
    std::reverse(temp.begin(), temp.end());
    ans.push_back(temp);
    return;
  }
  for (int i = 0; i < curr.size(); i++) {
    auto copy = curr;
    for (auto& ch : chars) {
      if (copy[i] == ch) continue;
      copy[i] = ch;
      if (map.find(copy) != map.end() && map.at(curr) == map.at(copy) + 1) {
        vec.push_back(copy);
        dfs(ans, map, chars, vec, beginWord);
        vec.pop_back();
      }
    }
  }
}

std::vector<std::vector<std::string>> findLaddersOptimal(std::string beginWord, std::string endWord,
                                                         std::vector<std::string>& wordList) {
  std::vector<std::vector<std::string>> ans;
  std::unordered_map<std::string, uint16_t> map;
  std::unordered_set<std::string> s(wordList.begin(), wordList.end());
  if (s.find(endWord) == s.end()) return ans;

  map[beginWord] = 0;
  const char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  std::queue<std::string> q;
  q.push(beginWord);
  s.erase(beginWord);

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();

    for (uint16_t i = 0; i < curr.size(); i++) {
      auto copy = curr;
      for (auto& ch : chars) {
        if (copy[i] == ch) continue;
        copy[i] = ch;
        if (s.find(copy) != s.end()) {
          map[copy] = map[curr] + 1;
          s.erase(copy);
          q.push(copy);
        }
      }
    }
  }

  // for (auto& [key, val] : map) {
  //   std::cout << key << " - " << val << std::endl;
  // }
  std::vector<std::string> path = {endWord};
  dfs(ans, map, chars, path, beginWord);
  return ans;
}

int main() {
  {
    std::string beginWord = "hit", endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    std::cout << "The minimum number of steps from beginWord to endWord = "
              << ladderLength(beginWord, endWord, wordList) << std::endl
              << std::endl;
  }
  {
    std::string beginWord = "hit", endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log"};  // missing "cog"
    std::cout << "Test 2:\n";
    std::cout << "Begin: " << beginWord << ", End: " << endWord << std::endl;
    std::cout << "Expected: 0 (no possible transformation since 'cog' not in wordList)" << std::endl;
    std::cout << "Output:   " << ladderLength(beginWord, endWord, wordList) << std::endl << std::endl;
  }
  {
    std::string beginWord = "game", endWord = "thee";
    std::vector<std::string> wordList = {"came", "cane", "bane", "bale", "bake", "bike", "like", "lire",
                                         "fire", "five", "hive", "hike", "hire", "here", "thee"};
    std::cout << "Test 3:\n";
    std::cout << "Begin: " << beginWord << ", End: " << endWord << std::endl;
    std::cout << "Expected: (depends on connections, likely > 6)" << std::endl;
    std::cout << "Output:   " << ladderLength(beginWord, endWord, wordList) << std::endl << std::endl;
  }

  {
    std::string beginWord = "talk", endWord = "tail";
    std::vector<std::string> wordList = {"tall", "tail", "balk", "tulk", "tark"};
    std::cout << "Test 4:\n";
    std::cout << "Begin: " << beginWord << ", End: " << endWord << std::endl;
    std::cout << "Expected: 3 (talk -> tall -> tail)" << std::endl;
    std::cout << "Output:   " << ladderLength(beginWord, endWord, wordList) << std::endl;
  }

  std::cout << "\n\nWord Ladder 2:\n\n";

  {
    std::string beginWord = "hit", endWord = "cog";
    std::vector<std::string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    std::cout << "Test 1:\n";
    std::cout << "Begin: " << beginWord << ", End: " << endWord << std::endl;
    std::cout << "Expected:\n";
    std::cout << "  [hit, hot, dot, dog, cog]\n";
    std::cout << "  [hit, hot, lot, log, cog]\n";
    auto res = findLaddersOptimal(beginWord, endWord, wordList);
    std::cout << "Output:\n";
    for (auto& path : res) {
      for (auto& w : path) std::cout << w << " ";
      std::cout << "\n";
    }
    std::cout << std::endl;
  }

  {
    std::string beginWord = "talk", endWord = "tail";
    std::vector<std::string> wordList = {"tall", "tail", "balk", "tulk", "tark"};
    std::cout << "Test 2:\n";
    std::cout << "Begin: " << beginWord << ", End: " << endWord << std::endl;
    std::cout << "Expected:\n";
    std::cout << "  [talk, tall, tail]\n";
    auto res = findLaddersOptimal(beginWord, endWord, wordList);
    std::cout << "Output:\n";
    for (auto& path : res) {
      for (auto& w : path) std::cout << w << " ";
      std::cout << "\n";
    }
    std::cout << std::endl;
  }
  return 0;
}
