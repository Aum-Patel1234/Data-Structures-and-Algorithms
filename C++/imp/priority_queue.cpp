#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // Comparator for the priority queue to create a min-heap based on ListNode
    // values. It returns true if 'a' has a greater value than 'b', meaning 'a'
    // should come after 'b'. This ensures that the smallest ListNode is always
    // on top of the priority queue.
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };

    std::priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
    for (auto temp : lists) {
      while (temp != nullptr) {
        pq.push(temp);
        temp = temp->next;
      }
    }
    if (pq.empty())
      return nullptr;

    ListNode *head = new ListNode(pq.top()->val);
    ListNode *temp = head;
    pq.pop();

    while (!pq.empty()) {
      ListNode *curr = pq.top();
      pq.pop();
      temp->next = new ListNode(curr->val);
      temp = temp->next;
    }
    temp->next = nullptr;
    return head;
  }
};

ListNode *createList(const vector<int> &nums) {
  if (nums.empty())
    return nullptr;

  ListNode *head = new ListNode(nums[0]);
  ListNode *temp = head;

  for (int i = 1; i < nums.size(); ++i) {
    temp->next = new ListNode(nums[i]);
    temp = temp->next;
  }

  return head;
}

void printList(ListNode *head) {
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Create example input: [[1,4,5],[1,3,4],[2,6]]
  vector<ListNode *> lists;

  lists.push_back(createList({1, 4, 5}));
  lists.push_back(createList({1, 3, 4}));
  lists.push_back(createList({2, 6}));

  Solution sol;
  ListNode *merged = sol.mergeKLists(lists);

  cout << "Merged List: ";
  printList(merged);

  return 0;
}
