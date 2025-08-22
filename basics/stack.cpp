#include <iostream>
#include <queue>

class Stack {
private:
  int *arr;
  int size;
  int capacity;

public:
  Stack() {
    size = 0;
    capacity = 10;
    arr = new int[10];
  }
  ~Stack() { delete arr; }

  void push(int x) {
    if (size == capacity) {
      capacity *= 2;
      int *newArr = new int[capacity];
      for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
      }
      delete[] arr;
      arr = newArr;
    }
    arr[size] = x;
    size++;
  }

  int pop() {
    if (size == 0)
      return -1;
    size--;
    return arr[size];
  }

  bool empty() { return size == 0; }

  int top() { return empty() ? -1 : arr[size - 1]; }
};

// NOTE: stack using queue
class MyStack {
private:
  std::queue<int> *q1, *q2;
  int rear = -1;

public:
  MyStack() {
    q1 = new std::queue<int>();
    q2 = new std::queue<int>();
  }
  ~MyStack() {
    delete q1;
    delete q2;
  }

  void push(int x) {
    rear = x;
    q1->push(x);
  }

  int pop() {
    while (q1->size() != 1) {
      q2->push(q1->front());
      q1->pop();
    }
    int ans = q1->front();
    q1->pop();
    while (!q2->empty()) {
      rear = q2->front();
      q2->pop();
      q1->push(rear);
    }
    return ans;
  }

  int top() { return rear; }

  bool empty() { return q1->size() == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {
  std::cout << "---- Stack Impelentation ----\n";
  Stack st;
  st.push(10);
  st.push(20);
  st.push(30);

  std::cout << "Top element: " << st.top() << "\n";   // 30
  std::cout << "Pop: " << st.pop() << "\n";           // 30
  std::cout << "Top after pop: " << st.top() << "\n"; // 20

  while (!st.empty()) {
    std::cout << "Popping: " << st.pop() << "\n";
  }

  std::cout << "Stack empty? " << (st.empty() ? "Yes" : "No") << "\n";

  return 0;
}
