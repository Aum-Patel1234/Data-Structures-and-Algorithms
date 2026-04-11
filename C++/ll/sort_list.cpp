#include <cassert>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 private:
  void swap(ListNode* a_prev, ListNode* a, ListNode* b_prev, ListNode* b) {
    if (!a || !b || a == b) return;
    if (a->next == b) {
      a_prev->next = b;
      a->next = b->next;
      b->next = a;
      return;
    }

    ListNode* temp = b->next;
    a_prev->next = b;
    b->next = a->next;

    b_prev->next = a;
    a->next = temp;
  }

  ListNode* find_next_small_node(ListNode* curr, ListNode*& prev_small) {
    if (!curr) return nullptr;

    ListNode* temp = curr->next;
    ListNode* prev = curr;
    while (temp) {
      if (temp->val < curr->val) {
        prev_small = prev;
        return temp;
      }
      prev = temp;
      temp = temp->next;
    }
    return nullptr;
  }

  void insertionSort(ListNode* node, ListNode* prev) {
    if (!node || !node->next) return;

    ListNode *pivot = node, *prev_small = nullptr;
    ListNode* next_small = find_next_small_node(pivot, prev_small);

    if (next_small) {
      swap(prev, pivot, prev_small, next_small);
      // pivot is now at next_small's old position
      // so we should continue sorting from prev->next
      insertionSort(prev->next, prev);
    } else
      insertionSort(node->next, node);
  }

 public:
  ListNode* sortList(ListNode* head) {
    ListNode dummy(INT_MIN, head);
    insertionSort(head, &dummy);
    return dummy.next;
  }
};

ListNode* make_list(const std::vector<int>& vec) {
  ListNode head(0);
  ListNode* temp = &head;
  for (int num : vec) {
    temp->next = new ListNode(num);
    temp = temp->next;
  }

  return head.next;
}
void delete_list(ListNode* head) {
  while (head) {
    ListNode* next = head->next;
    delete head;
    head = next;
  }
}
void print_list(ListNode* head) {
  while (head) {
    std::cout << head->val << " -> ";
    head = head->next;
  }
  std::cout << "null\n";
}
bool is_sorted(ListNode* head) {
  if (!head) return true;
  ListNode* next = head->next;
  while (next) {
    if (next->val < head->val) return false;
    head = next;
    next = next->next;
  }
  return true;
}

int main() {
  Solution s;
  std::vector<std::vector<int>> tests = {{},
                                         {1},
                                         {2, 1},
                                         {1, 2, 3, 4, 5},
                                         {5, 4, 3, 2, 1},
                                         {4, 2, 2, 1, 3},
                                         {0, -1, -3, 2, 1},
                                         {3, 1, 2},
                                         {2, 3, 1},
                                         {10, -1, 3, 5, 2, 8}};

  for (auto& t : tests) {
    ListNode* node = make_list(t);
    print_list(node);
    node = s.sortList(node);
    print_list(node);
    assert(is_sorted(node));
    delete_list(node);
    std::cout << "------\n";
  }
  std::cout << "\033[32mAll test cases passed!\033[0m\n";

  return 0;
}
