#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
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
  return 0;
}
