#include "main.hpp"
#include <iostream>
#include <vector>

// constructors
DequeNode::DequeNode(int x) : val(x), prev(nullptr), next(nullptr) {}
Deque::Deque() : front(nullptr), back(nullptr), size(0) {}
Deque::~Deque() {
  while (front) {
    DequeNode *next = front->next;
    delete front;
    front = next;
  }
}

void Deque::pushFront(int x) {
  size++;
  if (front == nullptr) {
    front = back = new DequeNode(x);
    return;
  }
  DequeNode *head = new DequeNode(x);
  head->next = front;
  front->prev = head;
  front = head;
}

void Deque::pushBack(int x) {
  size++;
  if (back == nullptr) {
    front = back = new DequeNode(x);
    return;
  }
  DequeNode *tail = new DequeNode(x);
  back->next = tail;
  tail->prev = back;
  back = tail;
}

void Deque::popFront() {
  if (front == nullptr) {
    std::cout << "List is Empty\n";
    return;
  }
  size--;
  if (front == back) {
    delete front;
    front = back = nullptr;
    return;
  }
  DequeNode *next = front->next;
  next->prev = nullptr;
  delete front;
  front = next;
}

void Deque::popBack() {
  if (back == nullptr) {
    std::cout << "List is Empty.\n";
    return;
  }
  size--;
  if (front == back) {
    delete front;
    front = back = nullptr;
    return;
  }
  DequeNode *prev = back->prev;
  prev->next = nullptr;
  delete back;
  back = prev;
}

int Deque::getFront() { return front ? front->val : -1; }
int Deque::getBack() { return back ? back->val : -1; }
bool Deque::isEmpty() { return front == nullptr; }
int Deque::getSize() { return size; }
void Deque::clear() {
  while (front) {
    DequeNode *next = front->next;
    delete front;
    front = next;
  }
  back = nullptr;
  size = 0;
}
void Deque::display() {
  std::cout << "NULL <- ";
  DequeNode *temp = front;
  while (temp) {
    std::cout << temp->val;
    if (temp->next)
      std::cout << " <-> ";
    temp = temp->next;
  }
  std::cout << " -> NULL\n";
}
std::vector<int> Deque::toVector() {
  std::vector<int> vec;
  DequeNode *temp = front;
  while (temp) {
    vec.emplace_back(temp->val);
    temp = temp->next;
  }
  return vec;
}

// ---------- Helpers (keep if not already present) ----------
void report(const std::string &name, bool ok) {
  std::cout << name << " : " << (ok ? "PASS" : "FAIL") << "\n";
}

bool vecEqual(const std::vector<int> &a, const std::vector<int> &b) {
  if (a.size() != b.size())
    return false;
  for (size_t i = 0; i < a.size(); ++i)
    if (a[i] != b[i])
      return false;
  return true;
}

// ---------- Test cases (use your Deque implementation above) ----------
// T1: Empty-deque behavior
bool test_empty_behavior() {
  Deque d;
  bool ok = true;
  ok &= d.isEmpty();
  ok &= (d.getSize() == 0);
  ok &= (d.getFront() == -1);
  ok &= (d.getBack() == -1);
  d.popFront(); // should be safe
  d.popBack();  // should be safe
  ok &= d.isEmpty();
  ok &= (d.getSize() == 0);
  return ok;
}

// T2: pushBack ordering and size
bool test_pushBack_order() {
  Deque d;
  d.pushBack(1);
  d.pushBack(2);
  d.pushBack(3);
  bool ok = true;
  // d.display();
  ok &= !d.isEmpty();
  ok &= (d.getSize() == 3);
  ok &= (d.getFront() == 1);
  ok &= (d.getBack() == 3);
  std::vector<int> expect = {1, 2, 3};
  ok &= vecEqual(d.toVector(), expect); // requires toVector() helper in Deque
                                        // or implement check manually
  return ok;
}

// T3: pushFront ordering and size
bool test_pushFront_order() {
  Deque d;
  d.pushFront(10);
  d.pushFront(20);
  d.pushFront(30); // deque should be 30,20,10
  bool ok = true;
  ok &= (d.getSize() == 3);
  ok &= (d.getFront() == 30);
  ok &= (d.getBack() == 10);
  std::vector<int> expect = {30, 20, 10};
  ok &= vecEqual(d.toVector(), expect);
  return ok;
}

// T4: Mixed pushes/pops behavior and order correctness
bool test_mixed_operations() {
  Deque d;
  d.pushBack(1);
  d.pushFront(2);
  d.pushBack(3); // [2,1,3]
  bool ok = true;
  ok &= vecEqual(d.toVector(), std::vector<int>{2, 1, 3});
  ok &= (d.getFront() == 2);
  ok &= (d.getBack() == 3);

  d.popFront(); // [1,3]
  ok &= (d.getFront() == 1);
  ok &= (d.getSize() == 2);

  d.popBack(); // [1]
  ok &= (d.getBack() == 1);
  ok &= (d.getSize() == 1);

  d.popFront(); // []
  ok &= d.isEmpty();
  ok &= (d.getSize() == 0);
  ok &= (d.getFront() == -1 && d.getBack() == -1);
  return ok;
}

// T5: Clear + stress (push many, pop all)
bool test_clear_and_stress() {
  Deque d;
  for (int i = 0; i < 50; ++i)
    d.pushBack(i);
  bool ok = (d.getSize() == 50);
  d.clear();
  ok &= d.isEmpty();
  ok &= (d.getSize() == 0);
  ok &= (d.getFront() == -1 && d.getBack() == -1);

  const int N = 1000;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0)
      d.pushFront(i);
    else
      d.pushBack(i);
  }
  ok &= (d.getSize() == N);

  int count = 0;
  while (!d.isEmpty()) {
    d.popFront();
    ++count;
  }
  ok &= (count == N);
  ok &= d.isEmpty();
  ok &= (d.getFront() == -1 && d.getBack() == -1);
  return ok;
}

// ---------- main() that runs all tests ----------
int main() {
  std::cout << "Running Deque tests...\n\n";

  report("T1 - Empty behavior", test_empty_behavior());
  report("T2 - pushBack order", test_pushBack_order());
  report("T3 - pushFront order", test_pushFront_order());
  report("T4 - Mixed ops (push/pop) behavior", test_mixed_operations());
  report("T5 - Clear & Stress test (push/pop many)", test_clear_and_stress());

  std::cout << "\nAll tests completed.\n";
  return 0;
}
