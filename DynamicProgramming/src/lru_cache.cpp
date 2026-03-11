#include <cassert>
#include <cstdint>
#include <iostream>
#include <unordered_map>

class LRUCache {
 private:
  typedef struct Node {
    int key, val;
    Node *prev, *next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    Node() : key(0), val(0), prev(nullptr), next(nullptr) {}
  } Node;

  Node *head, *tail;
  uint16_t size, capacity;
  std::unordered_map<int, Node*> map;

  void push(int k, int v) {
    Node* node = new Node(k, v);
    if (!head)
      head = node;
    else {
      tail->next = node;
      node->prev = tail;
    }
    tail = node;
    map[k] = node;
    size++;
  }
  void pop() {
    if (!head) return;
    Node *curr = head, *next = head->next;
    map.erase(curr->key);
    delete curr;
    head = next;
    if (head)
      head->prev = nullptr;
    else
      tail = nullptr;
    size--;
  }
  void moveToFront(Node* node) {
    if (node == tail) return;
    Node *prev = node->prev, *next = node->next;
    if (prev) prev->next = next;
    if (next) next->prev = prev;

    if (node == head) head = next;

    node->prev = tail;
    node->next = nullptr;
    tail->next = node;
    tail = node;
  }

 public:
  LRUCache(int capacity) : head(nullptr), tail(nullptr), size(0), capacity(capacity) {}
  ~LRUCache() {
    for (uint16_t i = 0; i < size; ++i) {
      Node* next = head->next;
      delete head;
      head = next;
    }
    tail = nullptr;
    assert(head == nullptr);
  }

  int get(int key) {
    if (!map.count(key)) return -1;
    Node* node = map[key];
    moveToFront(node);
    return node->val;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      Node* node = map[key];
      node->val = value;
      moveToFront(node);
      return;
    }
    if (size >= capacity) pop();
    push(key, value);
  }
};

int main() {
  {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    assert(cache.get(1) == 1);  // returns 1

    cache.put(3, 3);             // evicts key 2
    assert(cache.get(2) == -1);  // not found

    cache.put(4, 4);             // evicts key 1
    assert(cache.get(1) == -1);  // not found
    assert(cache.get(3) == 3);   // returns 3
    assert(cache.get(4) == 4);   // returns 4
  }

  {
    LRUCache cache(1);

    cache.put(1, 10);
    assert(cache.get(1) == 10);

    cache.put(2, 20);  // evicts key 1
    assert(cache.get(1) == -1);
    assert(cache.get(2) == 20);
  }

  {
    LRUCache cache(2);

    cache.put(2, 1);
    cache.put(2, 2);  // update existing
    assert(cache.get(2) == 2);

    cache.put(1, 1);
    cache.put(4, 1);  // evicts LRU
    assert(cache.get(2) == -1);
  }

  std::cout << "All tests passed!\n";
}
