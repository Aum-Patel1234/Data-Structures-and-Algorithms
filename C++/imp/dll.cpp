#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
  struct Node {
    int val;
    Node *next, *prev;

    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int v) : val(v), next(nullptr), prev(nullptr) {}
  };

  void deleteHead() {
    Node *prevHead = this->head;
    if (this->head == nullptr)
      return;
    this->head = this->head->next;
    if (this->head == nullptr)
      return;
    this->head->prev = nullptr;
    prevHead->next = nullptr;
    delete prevHead;
  }
  void deleteTail() {
    Node *prevTail = this->tail;
    if (prevTail == nullptr)
      return;
    this->tail = prevTail->prev;
    if (this->tail == nullptr) {
      this->head = nullptr;
    } else {
      this->tail->next = nullptr;
      prevTail->prev = nullptr;
    }
    delete prevTail;
  }

public:
  Node *head, *tail;
  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  int get(int index) {
    Node *temp = this->head;
    for (int i = 0; i < index && temp != nullptr; i++)
      temp = temp->next;
    return temp ? temp->val : -1;
  }

  void addAtHead(int val) {
    Node *newHead = new Node();
    newHead->val = val;
    if (this->head == nullptr) {
      this->head = newHead;
      this->tail = newHead;
      return;
    }
    newHead->prev = nullptr;
    newHead->next = this->head;
    this->head->prev = newHead;
    this->head = newHead;
  }

  void addAtTail(int val) {
    Node *newTail = new Node();
    newTail->val = val;
    if (this->head == nullptr) {
      this->head = newTail;
      this->tail = newTail;
      return;
    }
    newTail->prev = this->tail;
    newTail->next = nullptr;
    this->tail->next = newTail;
    this->tail = newTail;
  }

  void addAtIndex(int index, int val) {
    if (index == 0) {
      addAtHead(val);
      return;
    }
    Node *temp = this->head;
    for (int i = 1; i < index && temp != nullptr; i++)
      temp = temp->next;

    if (!temp)
      return;
    if (temp == this->tail) {
      addAtTail(val);
      return;
    }

    Node *newNode = new Node();
    newNode->val = val;
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    // temp = head;
    // while (temp != nullptr) {
    //     cout << temp->val << "\t";
    //     temp = temp->next;
    // }
    // cout << endl;
  }

  void deleteAtIndex(int index) {
    if (index == 0) {
      deleteHead();
      return;
    }
    Node *temp = this->head;
    for (int i = 0; i < index && temp; i++)
      temp = temp->next;

    if (!temp)
      return;
    if (temp == this->tail) {
      deleteTail();
      return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
  }
};

int main() {
  DoublyLinkedList dll;

  // Edge case: delete from empty list
  dll.deleteAtIndex(0);
  cout << "After deleteAtIndex(0) on empty: get(0) = " << dll.get(0)
       << " (expected -1)\n";

  // Test addAtHead and get
  dll.addAtHead(10);
  dll.addAtHead(20);
  cout << "List now: [20, 10], get(0)=" << dll.get(0)
       << " get(1)=" << dll.get(1) << "\n";

  // Test addAtTail
  dll.addAtTail(30);
  cout << "After addAtTail(30): [20,10,30], get(2)=" << dll.get(2) << "\n";

  // Test addAtIndex middle
  dll.addAtIndex(1, 15);
  // Expected [20,15,10,30]
  cout << "After addAtIndex(1,15): ";
  for (int i = 0; i < 4; ++i)
    cout << dll.get(i) << (i < 3 ? "," : "\n");

  // Edge case: addAtIndex past tail (should do nothing)
  dll.addAtIndex(10, 99);
  cout << "After addAtIndex(10,99) (out of bounds): size still 4, get(4)="
       << dll.get(4) << " (expected -1)\n";

  // Test deleteAtIndex head, middle, tail
  dll.deleteAtIndex(0); // removes 20
  dll.deleteAtIndex(1); // removes 10 (originally at index 2)
  dll.deleteAtIndex(1); // removes 30 (tail)
  // Now only one element (15) should remain
  cout << "After three deletes: get(0)=" << dll.get(0)
       << " get(1)=" << dll.get(1) << " (expected -1)\n";

  return 0;
}
