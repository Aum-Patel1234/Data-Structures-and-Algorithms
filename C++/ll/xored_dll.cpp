// #include <iso646.h>
//
// #include <cassert>
// #include <cstddef>
// #include <cstdint>
// #include <string>
// class BrowserHistory {
//  private:
//   template <typename T>
//   struct Node {
//     T val;
//     std::uintptr_t xored;
//
//     Node(const T& v) : val(v), xored(0) {}
//   };
//
//   template <typename T>
//   class LinkedList {
//    public:
//     Node<T>* head;
//     Node<T>* tail;
//     size_t size = 0;
//
//     LinkedList() : head(nullptr), tail(nullptr) {}
//     ~LinkedList() {
//       if (head == nullptr) {
//         assert(tail == nullptr);
//       }
//       // TODO:
//     }
//
//     void appendNode(T val, uintptr_t prevXored) {
//       size++;
//       if (!head) {
//         assert(tail == nullptr);
//         head = tail = new Node<T>(val);
//         return;
//       }
//       Node<T>* newNode = new Node<T>(val);
//       // IMPORTANT: xored = prev ^ next;
//       tail->xored ^= reinterpret_cast<uintptr_t>(newNode);
//       // here tail ^ 0 = tail
//       newNode->xored = reinterpret_cast<std::uintptr_t>(tail);
//       tail = newNode;
//     }
//
//     void popTillTail(Node<T>* curr, uintptr_t prev) {
//       if (curr == head) {
//         head = nullptr;
//       }
//       Node<T>* next = reinterpret_cast<Node<T>*>(reinterpret_cast<uintptr_t>(prev) ^ curr->xored);
//       size--;
//       prev = reinterpret_cast<uintptr_t>(curr);
//       curr = next;
//       while (curr != tail) {
//         next = reinterpret_cast<Node<T>*>((reinterpret_cast<uintptr_t>(prev) ^ curr->xored));
//         prev = reinterpret_cast<uintptr_t>(curr);
//         delete curr;
//         curr = next;
//         size--;
//       }
//       tail = curr;
//     }
//   };
//
//   LinkedList<std::string>* ll;
//
//  public:
//   BrowserHistory(std::string homepage) { ll = new LinkedList<std::string>(); }
//
//   void visit(std::string url) { ll->appendNode(url, ll->tail); }
//
//   std::string back(int steps) {}
//
//   std::string forward(int steps) {}
// };
//
// /**
//  * Your BrowserHistory object will be instantiated and called as such:
//  * BrowserHistory* obj = new BrowserHistory(homepage);
//  * obj->visit(url);
//  * string param_2 = obj->back(steps);
//  * string param_3 = obj->forward(steps);

int main() {};
