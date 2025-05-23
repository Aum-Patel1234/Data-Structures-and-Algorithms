#include <map>
#include <stdio.h>

class LRUCache {
private:
  struct Node {
    int key, val;
    struct Node *next, *prev;
  };

  std::map<int, Node *> loc;
  Node *head, *tail;
  int currSize;
  int capacity;

  void pushToLast(Node *curr) {
    if (curr == tail) {
      return;
    }
    if (curr->prev)
      curr->prev->next = curr->next;
    else // it is head
      head = head->next;
    if (curr->next)
      curr->next->prev = curr->prev;

    curr->next = nullptr;
    curr->prev = tail;
    if (tail)
      tail->next = curr;
    tail = curr;
  }

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head = nullptr;
    tail = nullptr;
    this->currSize = 0;
  }

  int get(int key) {
    if (this->loc.find(key) == this->loc.end()) {
      return -1;
    }

    Node *curr = this->loc[key];
    // bring push to the last
    pushToLast(curr);
    return curr->val;
  }

  void put(int key, int value) {
    if (this->loc.find(key) != this->loc.end()) {
      Node *curr = loc.at(key);
      curr->val = value;
      pushToLast(curr);
      return;
    }
    if (this->currSize == this->capacity) {
      Node *toRemove = head;
      loc.erase(toRemove->key);
      head = head->next;
      if (head)
        head->prev = nullptr;
      delete toRemove;
      currSize--;
    }
    Node *newNode = new Node();
    newNode->val = value;
    newNode->key = key;
    this->loc[key] = newNode;

    if (!head) {
      head = tail = newNode;
    } else {
      // insert at end
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }

    this->currSize++;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {}
