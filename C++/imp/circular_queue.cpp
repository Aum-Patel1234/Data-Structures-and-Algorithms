#include <iostream>
#include <vector>

using namespace std;
class MyCircularQueue {
private:
  int front, rear, size, currSize;
  vector<int> *queue;

public:
  MyCircularQueue(int k) {
    queue = new vector<int>(k);
    front = 0;
    rear = -1;
    size = k;
    currSize = 0;
  }
  ~MyCircularQueue() { delete queue; }

  bool enQueue(int value) {
    if (isFull())
      return false;
    currSize++;
    rear = (rear + 1) % size;
    (*queue)[rear] = value;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    currSize--;
    front = (front + 1) % size;
    return true;
  }

  int Front() { return isEmpty() ? -1 : (*queue)[front]; }

  int Rear() { return isEmpty() ? -1 : (*queue)[rear]; }

  bool isEmpty() { return currSize == 0; }

  bool isFull() { return currSize == size; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
  // Create a circular queue of size 3
  MyCircularQueue *obj = new MyCircularQueue(3);

  cout << boolalpha; // Print bools as true/false

  cout << "Enqueue 1: " << obj->enQueue(1) << endl; // true
  cout << "Enqueue 2: " << obj->enQueue(2) << endl; // true
  cout << "Enqueue 3: " << obj->enQueue(3) << endl; // true
  cout << "Enqueue 4 (should fail): " << obj->enQueue(4)
       << endl; // false (full)

  cout << "Rear: " << obj->Rear() << endl;      // 3
  cout << "Is Full: " << obj->isFull() << endl; // true

  cout << "Dequeue: " << obj->deQueue() << endl;    // true
  cout << "Enqueue 4: " << obj->enQueue(4) << endl; // true

  cout << "Rear after enqueue 4: " << obj->Rear() << endl; // 4

  cout << "Front: " << obj->Front() << endl;      // 2
  cout << "Is Empty: " << obj->isEmpty() << endl; // false

  delete obj;
  return 0;
}
