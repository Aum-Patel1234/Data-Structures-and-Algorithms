#include "main.hpp"
#include <iostream>

TrieNode::TrieNode() {
  flag = false;
  for (int i = 0; i < 26; i++) {
    children[i] = nullptr;
  }
}

Trie::Trie() { root = new TrieNode(); }
void clear(TrieNode *root) {
  if (!root)
    return;
  for (int i = 0; i < 26; i++) {
    TrieNode *temp = root->get(i);
    if (temp)
      clear(temp);
  }
  delete root;
}
Trie::~Trie() { clear(root); }

TrieNode *TrieNode::assign(int idx) {
  if (children[idx] == nullptr)
    children[idx] = new TrieNode();
  return children[idx];
}
TrieNode *TrieNode::get(int idx) { return children[idx]; }
bool TrieNode::isEnd() { return flag; }

void TrieNode::setEnd(bool v = true) { flag = v; }
void Trie::insert(const std::string &word) {
  TrieNode *temp = root;
  for (int i = 0; i < word.size(); i++) {
    int idx = word[i] - 'a';
    if (temp->get(idx) == nullptr)
      temp = temp->assign(idx);
    else
      temp = temp->get(idx);
  }
  temp->setEnd();
}
bool Trie::search(const std::string &word) const {
  TrieNode *temp = root;
  for (int i = 0; i < word.size(); i++) {
    int idx = word[i] - 'a';
    temp = temp->get(idx);
    if (!temp)
      return false;
  }
  return temp->isEnd();
}
bool Trie::startsWith(const std::string &prefix) const {
  TrieNode *temp = root;
  for (int i = 0; i < prefix.size(); i++) {
    int idx = prefix[i] - 'a';
    temp = temp->get(idx);
    if (!temp)
      return false;
  }
  return true;
}

using namespace std;

int main() {
  Trie trie;

  // Example insertions
  trie.insert("apple");
  trie.insert("app");
  trie.insert("bat");

  // Search tests
  cout << boolalpha; // print true/false instead of 1/0
  cout << "Search 'apple': " << trie.search("apple") << endl;
  cout << "Search 'app': " << trie.search("app") << endl;
  cout << "Search 'bat': " << trie.search("bat") << endl;
  cout << "Search 'bad': " << trie.search("bad") << endl;

  // StartsWith tests
  cout << "StartsWith 'ap': " << trie.startsWith("ap") << endl;
  cout << "StartsWith 'ba': " << trie.startsWith("ba") << endl;
  cout << "StartsWith 'cat': " << trie.startsWith("cat") << endl;

  return 0;
}
