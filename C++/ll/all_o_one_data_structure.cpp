#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

struct dll_node {
  string val;
  dll_node *prev, *next;
  dll_node(string val) : prev(nullptr), next(nullptr), val(val) {}
  dll_node(string val, dll_node* prev, dll_node* next) : prev(prev), next(next), val(val) {}
};

class DLL {
 private:
  dll_node *head, *tail;

 public:
  DLL() : head(nullptr), tail(nullptr) {}
  ~DLL() {
    while (head) {
      dll_node* next = head->next;
      delete head;
      head = next;
    }

    tail = nullptr;
  }

  bool empty() { return head == nullptr; }
  string get_head_val() { return head ? head->val : ""; }
  string get_tail_val() { return tail ? tail->val : ""; }

  dll_node* push_node(dll_node* node) {
    // VERY IMPORTANT
    node->prev = nullptr;
    node->next = nullptr;

    if (!head) {
      head = tail = node;
    } else {
      tail->next = node;
      node->prev = tail;
      tail = node;
    }

    return node;
  }

  dll_node* push(string val) { return push_node(new dll_node(val)); }

  string remove_back() {
    if (!tail) return "";

    string val = tail->val;
    dll_node* node = detach_back();
    delete node;
    return val;
  }

  string remove_front() {
    if (!head) return "";

    string val = head->val;
    dll_node* node = detach_front();
    delete node;
    return val;
  }

  // detach means remvoe from dll but not delete node itself
  dll_node* detach_front() {
    if (!head) return nullptr;

    dll_node* node = head;

    if (head == tail) {
      head = tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
    }

    node->prev = nullptr;
    node->next = nullptr;

    return node;
  }

  dll_node* detach_back() {
    if (!tail) return nullptr;

    dll_node* node = tail;

    if (head == tail) {
      head = tail = nullptr;
    } else {
      tail = tail->prev;
      tail->next = nullptr;
    }

    node->prev = nullptr;
    node->next = nullptr;

    return node;
  }

  dll_node* detach_node(dll_node* node) {
    if (!node) return nullptr;

    if (head == tail) {
      head = tail = nullptr;
    } else if (node == head) {
      head = head->next;
      head->prev = nullptr;
    } else if (node == tail) {
      tail = tail->prev;
      tail->next = nullptr;
    } else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    node->prev = nullptr;
    node->next = nullptr;

    return node;
  }

  // remove and delete
  string remove_node(dll_node* node) {
    if (!node) return "";

    string val = node->val;
    detach_node(node);
    delete node;
    return val;
  }
};

class AllOne {
 private:
  unordered_map<string, pair<uint, dll_node*>> key_info;
  map<uint, DLL*> freq_map;

 public:
  // 1. ordered set with num occurence as key and dll as val
  // 2. case when key is inserted remove from curr key in dll
  //    which will be stored in another map<string,int> and add it here also
  // 3. case when key is decremented, decrement then occurence counting map
  //    then remove it from dll, on another thought occurence counting map
  //    can also store address i.e  map<string, pair<count, dll_ptr_address>>
  // 4. getMaxKey -> dll is ordered set so top level key and tail of the dll
  // 5. getMinKey -> same way but opposite
  AllOne() {}
  ~AllOne() {
    for (auto& [freq, dll] : freq_map) {
      delete dll;
    }
  }

  void inc(string key) {
    if (!key_info.count(key)) {
      DLL* dll;
      if (!freq_map.count(1)) {
        dll = new DLL();
        freq_map[1] = dll;
      } else
        dll = freq_map.at(1);

      dll_node* node = dll->push(key);
      key_info[key] = {1, node};
      return;
    }

    auto& [freq, node] = key_info.at(key);
    // detach from curr freq
    DLL* dll = freq_map.at(freq);
    dll->detach_node(node);
    if (dll->empty()) {
      delete dll;
      freq_map.erase(freq);
    }

    // move it to next one
    freq++;
    if (!freq_map.count(freq)) {
      dll = new DLL();
      freq_map[freq] = dll;
    } else
      dll = freq_map.at(freq);
    dll->push_node(node);
  }

  void dec(string key) {
    // if(!key_info.count(key))
    //   return;

    auto& [freq, node] = key_info.at(key);
    DLL* dll = freq_map.at(freq);
    if (freq == 1) {
      dll->remove_node(node);
      if (dll->empty()) {
        delete dll;
        freq_map.erase(1);
      }
      key_info.erase(key);
      return;
    }

    node = dll->detach_node(node);
    if (dll->empty()) {
      delete dll;
      freq_map.erase(freq);
    }

    freq--;
    if (!freq_map.count(freq)) {
      freq_map[freq] = new DLL();
    }
    DLL* next_dll = freq_map.at(freq);
    node = next_dll->push_node(node);
    key_info[key] = {freq, node};
  }

  string getMaxKey() {
    if (freq_map.empty()) return "";

    return freq_map.rbegin()->second->get_tail_val();
  }

  string getMinKey() {
    if (freq_map.empty()) return "";

    return freq_map.begin()->second->get_tail_val();
  }
};

int main() {
  {
    AllOne obj;

    obj.inc("hello");
    obj.inc("hello");

    assert(obj.getMaxKey() == "hello");
    assert(obj.getMinKey() == "hello");
  }

  {
    AllOne obj;

    obj.inc("a");
    obj.inc("b");
    obj.inc("b");
    obj.inc("c");
    obj.inc("c");
    obj.inc("c");

    assert(obj.getMaxKey() == "c");
    assert(obj.getMinKey() == "a");
  }

  {
    AllOne obj;

    obj.inc("apple");
    obj.inc("banana");
    obj.inc("banana");

    obj.dec("banana");

    string mx = obj.getMaxKey();
    string mn = obj.getMinKey();

    // both freq = 1
    assert((mx == "apple" || mx == "banana") && (mn == "apple" || mn == "banana"));
  }

  {
    AllOne obj;

    obj.inc("x");
    obj.inc("x");
    obj.inc("y");

    obj.dec("x");
    obj.dec("x");

    assert(obj.getMaxKey() == "y");
    assert(obj.getMinKey() == "y");
  }

  {
    AllOne obj;

    obj.inc("dog");
    obj.inc("cat");
    obj.inc("dog");
    obj.inc("bird");
    obj.inc("bird");
    obj.inc("bird");

    obj.dec("bird");
    obj.dec("dog");

    string mx = obj.getMaxKey();
    string mn = obj.getMinKey();

    // bird and dog freq = 2
    // cat freq = 1

    assert(mx == "bird" || mx == "dog");
    assert(mn == "cat" || mn == "dog");
  }

  cout << "All test cases passed!\n";

  return 0;
}
