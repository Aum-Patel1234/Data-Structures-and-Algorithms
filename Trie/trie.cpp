#include <iostream>
#include <string>  // Include this for std::string

using namespace std;

struct Node {
    Node* nodes[26];
    bool flag = false;
    bool containsKey(char ch) { return nodes[ch - 'a'] != NULL; }
    void createNode(Node* node, char ch) {
        nodes[ch - 'a'] = node;
    }
    Node* get(char ch) { return nodes[ch - 'a']; }
    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->createNode(new Node(), word[i]);
            }
            node = node->get(word[i]);
        }
        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie trie;
    
    // Insert words into the trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("batman");

    // Test search function
    cout << "Search for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search for 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search for 'batman': " << (trie.search("batman") ? "Found" : "Not Found") << endl;
    cout << "Search for 'batmobile': " << (trie.search("batmobile") ? "Found" : "Not Found") << endl;

    // Test startsWith function
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "Yes" : "No") << endl;
    cout << "Starts with 'bat': " << (trie.startsWith("bat") ? "Yes" : "No") << endl;
    cout << "Starts with 'batm': " << (trie.startsWith("batm") ? "Yes" : "No") << endl;
    cout << "Starts with 'cat': " << (trie.startsWith("cat") ? "Yes" : "No") << endl;

    return 0;
}
