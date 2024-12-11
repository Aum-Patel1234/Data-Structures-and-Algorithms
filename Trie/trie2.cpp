#include<iostream>
#include<string>
using namespace std;

class Trie {
private:
  struct Node {
    Node *nodes[26];
    int countEndWith = 0;
    int countPrefix = 0;

    void put(Node *node, char ch) { nodes[ch - 'a'] = node; }

    bool containsKey(char ch) { return nodes[ch - 'a'] != NULL; }

    Node *get(char ch) { return nodes[ch - 'a']; }
  };

public:
  Node *root;

  Trie() {
    // Write your code here->
    root = new Node();
  }

  void insert(string word) {
    // Write your code here->
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node->get(word[i]) == NULL) {
        node->put(new Node(), word[i]);
      }
      node = node->get(word[i]);
      node->countPrefix++;
    }
    node->countEndWith++;
  }

  int countWordsEqualTo(string word) {
    // Write your code here->
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) {
        return 0;
      }
      node = node->get(word[i]);
    }
    return node->countEndWith;
  }

  int countWordsStartingWith(string word) {
    // Write your code here->
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node->containsKey(word[i])) {
        return 0;
      }
      node = node->get(word[i]);
    }
    return node->countPrefix;
  }

  void erase(string word) {
    // Write your code here->
    Node *node = root;
    for (int i = 0; i < word.length(); i++) {
      char ch = word[i];
      if (node->containsKey(ch)) {
        node = node->get(ch);
        node->countPrefix--;
      } else {
        return; // Word not found, nothing to erase
      }
    }
    node->countEndWith--;
  }
};

int main() {
    Trie trie;

    // Insert words into the Trie
    string word1 = "apple";
    string word2 = "app";
    string word3 = "apricot";
    
    trie.insert(word1);
    trie.insert(word2);
    trie.insert(word3);

    // Test countWordsEqualTo
    cout << "Count of word 'apple': " << trie.countWordsEqualTo(word1) << endl;
    cout << "Count of word 'app': " << trie.countWordsEqualTo(word2) << endl;
    cout << "Count of word 'banana': " << trie.countWordsEqualTo("banana") << endl; // Not inserted, should be 0

    // Test countWordsStartingWith
    cout << "Count of words starting with 'ap': " << trie.countWordsStartingWith("ap") << endl;
    cout << "Count of words starting with 'app': " << trie.countWordsStartingWith("app") << endl;
    cout << "Count of words starting with 'ban': " << trie.countWordsStartingWith("ban") << endl; // Not inserted, should be 0

    // Erase word and test
    trie.erase(word1); // Erase "apple"
    cout << "Count of word 'apple' after erasing: " << trie.countWordsEqualTo(word1) << endl;
    cout << "Count of words starting with 'ap' after erasing 'apple': " << trie.countWordsStartingWith("ap") << endl;

    return 0;
}