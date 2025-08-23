#include "main.hpp"
#include <iostream>

MyQueue::MyQueue() {
  arr = new int[10];
  front = 0;
  rear = 0;
  capacity = 10;
}
MyQueue::~MyQueue() { delete[] arr; }

void MyQueue::push(int val) {
  if (rear == capacity) {
    int *prevArr = arr;
    int size = rear - front;
    capacity *= 2;
    arr = new int[capacity];

    for (int i = 0; i < size; i++) {
      arr[i] = prevArr[front + i];
    }
    rear++;
    front = 0;
    rear = size;
    delete[] prevArr;
  }
  arr[rear++] = val;
}
int MyQueue::pop() {
  if (front == rear) {
    front = rear = 0;
    return -1;
  }
  return arr[front++];
}

int MyQueue::size() const { return rear - front; }
bool MyQueue::empty() const { return rear == front; }

void printResult(const char *name, bool ok) {
  std::cout << name << ": " << (ok ? "PASS" : "FAIL") << "\n";
}

int main() {
  // Test 1: empty behavior
  {
    MyQueue q;
    bool ok = true;
    ok &= q.empty();
    ok &= (q.size() == 0);
    ok &= (q.pop() == -1);
    printResult("Test 1 - empty behavior", ok);
  }

  // Test 2: single push/pop
  {
    MyQueue q;
    q.push(10);
    bool ok = true;
    ok &= !q.empty();
    ok &= (q.size() == 1);
    ok &= (q.pop() == 10);
    ok &= q.empty();
    printResult("Test 2 - single push/pop", ok);
  }

  // Test 3: FIFO order without resize (push exactly capacity)
  {
    MyQueue q;
    bool ok = true;
    for (int i = 1; i <= 10; ++i)
      q.push(i);
    ok &= (q.size() == 10);
    for (int i = 1; i <= 10; ++i) {
      int v = q.pop();
      if (v != i)
        ok = false;
    }
    ok &= q.empty();
    printResult("Test 3 - FIFO without resize", ok);
  }

  // Test 4: Resize when front == 0 (simple resize)
  {
    MyQueue q;
    bool ok = true;
    for (int i = 1; i <= 12; ++i)
      q.push(i); // triggers resize once
    if (q.size() != 12)
      ok = false;
    for (int i = 1; i <= 12; ++i) {
      int v = q.pop();
      if (v != i)
        ok = false;
    }
    ok &= q.empty();
    printResult("Test 4 - resize with front==0", ok);
  }

  // Test 5: Resize after some pops (this often reveals copy-from-wrong-index
  // bug) Expected behavior: push 1..10, pop 1..5, then push 11..20 (causes
  // resize), then popping should return 6..20 in order.
  {
    MyQueue q;
    bool ok = true;
    // push 1..10
    for (int i = 1; i <= 10; ++i)
      q.push(i);
    // pop 1..5
    for (int i = 1; i <= 5; ++i) {
      int v = q.pop();
      if (v != i)
        ok = false;
    }
    // push 11..20 -> should trigger resize because rear == capacity (10)
    for (int i = 11; i <= 20; ++i)
      q.push(i);

    // Now pop remaining: expect 6..20
    int expect = 6;
    while (!q.empty()) {
      int v = q.pop();
      if (v != expect) {
        ok = false;
        std::cout << "  MISMATCH at Test 5: expected " << expect << " got " << v
                  << "\n";
      }
      expect++;
    }
    if (expect != 21)
      ok = false; // ensure we popped exactly up to 20
    printResult("Test 5 - resize after pops (checks copy correctness)", ok);
  }

  // Test 6: Alternating push/pop to simulate real usage
  {
    MyQueue q;
    bool ok = true;
    q.push(100);
    q.push(200);
    if (q.pop() != 100)
      ok = false;
    q.push(300);
    if (q.pop() != 200)
      ok = false;
    if (q.pop() != 300)
      ok = false;
    if (!q.empty())
      ok = false;
    printResult("Test 6 - alternating push/pop", ok);
  }

  // Summary note for user visibility
  std::cout << "\nNote: If Test 5 fails, your queue's resize logic likely "
               "copies from index 0\n"
            << "instead of starting from 'front'. That produces incorrect "
               "order after\n"
            << "popping some elements and then forcing a resize.\n";

  return 0;
}
