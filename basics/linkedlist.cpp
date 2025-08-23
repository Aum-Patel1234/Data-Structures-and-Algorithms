#include "main.hpp"
#include <iostream>

ListNode::ListNode(int val) : val(val), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}
LinkedList::~LinkedList() {
  while (head != nullptr) {
    ListNode *curr = head;
    head = head->next;
    delete curr;
  }
}

void LinkedList::insertFront(int x) {
  ListNode *prevHead = head;
  head = new ListNode(x);
  head->next = prevHead;
}

void LinkedList::insertBack(int x) {
  if (head == nullptr) {
    insertFront(x);
    return;
  }
  ListNode *temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = new ListNode(x);
}

void LinkedList::insertAt(int pos, int x) {
  if (pos <= 0) {
    std::cout << "Invalid position\n";
    return;
  }
  if (pos == 1) {
    insertFront(x);
    return;
  }
  ListNode *temp = head;
  int idx = 1;
  while (temp != nullptr && idx < pos - 1) {
    temp = temp->next;
  }
  if (temp == nullptr) {
    std::cout << "Pos out of the length of list\n";
    return;
  }
  ListNode *node = new ListNode(x);
  node->next = temp->next;
  temp->next = node;
}

void LinkedList::removeFront() {
  ListNode *prevHead = head;
  if (prevHead == nullptr)
    return;
  head = head->next;
  delete prevHead;
}

void LinkedList::removeBack() {
  if (head == nullptr)
    return;
  if (head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }
  ListNode *temp = head, *prev = head;
  while (temp->next != nullptr) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = nullptr;
  delete temp;
}

void LinkedList::removeAt(int pos) {
  if (head == nullptr) {
    std::cout << "List is empty.\n";
    return;
  }
  if (pos <= 0) {
    std::cout << "Invalid position\n";
    return;
  }
  if (pos == 1) {
    ListNode *newHead = head->next;
    delete head;
    head = newHead;
    return;
  }
  ListNode *temp = head;
  int idx = 1;
  while (temp != nullptr && idx < pos - 1) {
    temp = temp->next;
    idx++;
  }
  if (temp == nullptr || temp->next == nullptr) {
    std::cout << "Pos out of the length of list\n";
    return;
  }
  ListNode *nodeToDelete = temp->next;
  temp->next = temp->next->next;
  delete nodeToDelete;
}

int LinkedList::search(int x) {
  int idx = 0;
  ListNode *temp = head;
  while (temp) {
    if (temp->val == x)
      return idx;
    idx++;
    temp = temp->next;
  }
  return -1;
}

void LinkedList::reverse() {
  ListNode *prev = nullptr;
  ListNode *curr = head;
  while (curr != nullptr) {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

int LinkedList::length() {
  int len = 0;
  ListNode *temp = head;
  while (temp) {
    len++;
    temp = temp->next;
  }
  return len;
}
void LinkedList::display() {
  ListNode *temp = head;
  std::cout << std::endl;
  while (temp) {
    std::cout << temp->val << " -> ";
    temp = temp->next;
  }
  std::cout << "TAIL\n";
}

int main() {
  using std::cout;
  using std::endl;

  // Test 1: empty behavior & no-op deletes
  {
    LinkedList list;
    bool ok = true;
    ok &= (list.length() == 0);
    list.removeFront();
    list.removeBack();
    list.removeAt(0);
    ok &= (list.length() == 0);
    ok &= (list.search(42) == -1);
    cout << "Test 1 - empty behavior: " << (ok ? "PASS" : "FAIL") << endl;
  }

  // Test 2: insertFront, insertBack, insertAt, removeAt (middle)
  {
    LinkedList list;
    bool ok = true;
    list.insertFront(10); // [10]
    ok &= (list.length() == 1 && list.search(10) == 0);
    list.insertBack(20); // [10,20]
    ok &= (list.length() == 2 && list.search(20) == 1);
    list.insertAt(1, 15); // [10,15,20]
    ok &= (list.search(15) == 0 && list.search(20) == 2);
    list.removeAt(1); // [10,20]
    ok &= (list.search(15) == -1 && list.search(20) == 1 && list.length() == 2);
    cout << "Test 2 - insert/remove middle: " << (ok ? "PASS" : "FAIL") << endl;
  }

  // Test 3: removeFront/removeBack correctness after several inserts
  {
    LinkedList list;
    bool ok = true;
    for (int i = 1; i <= 5; ++i)
      list.insertBack(i); // [1,2,3,4,5]
    ok &= (list.length() == 5 && list.search(1) == 0 && list.search(5) == 4);
    list.removeFront(); // removes 1 -> [2,3,4,5]
    ok &= (list.length() == 4 && list.search(1) == -1);
    list.removeBack(); // removes 5 -> [2,3,4]
    ok &= (list.length() == 3 && list.search(5) == -1);
    cout << "Test 3 - pop front/back: " << (ok ? "PASS" : "FAIL") << endl;
  }

  // Test 4: reverse, search positions and out-of-bounds removes
  {
    LinkedList list;
    bool ok = true;
    for (int i = 1; i <= 5; ++i)
      list.insertBack(i); // [1,2,3,4,5]
    list.reverse();       // [5,4,3,2,1]
    ok &= (list.length() == 5 && list.search(5) == 0 && list.search(1) == 4);
    int before = list.length();
    list.removeAt(100); // should be a no-op (out-of-bounds)
    ok &= (list.length() == before);
    cout << "Test 4 - reverse + bounds: " << (ok ? "PASS" : "FAIL") << endl;
  }

  return 0;
}
