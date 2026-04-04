#include <cassert>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ReservoirSampler {
 private:
  std::vector<ListNode*> reservoir;
  ListNode *listHead, *lastNode;
  std::mt19937 gen;
  size_t currIdx, k;

 public:
  ReservoirSampler(ListNode* head, size_t k) : listHead(head), currIdx(0), k(k) {
    std::random_device rd;
    gen = std::mt19937(rd());
  }

  int getRandomNumber(int limit) {
    std::uniform_int_distribution<> dist(0, limit - 1);  // range [0, limit-1]
    return dist(gen);
  }

  // // NOTE: O(k)
  // int getRandom() {
  //   if (!lastNode) {
  //     lastNode = listHead;
  //     currIdx = 0;
  //     reservoir.clear();
  //
  //     int size = k;
  //     while (size-- && lastNode) {
  //       reservoir.push_back(lastNode);
  //       lastNode = lastNode->next;
  //     }
  //   }
  //
  //   if (!lastNode) return reservoir[getRandomNumber(reservoir.size())]->val;
  //
  //   int j = getRandomNumber(currIdx + 1);
  //   ListNode* currNode = lastNode;
  //   lastNode = lastNode->next;
  //   currIdx++;
  //
  //   if (j < k) {
  //     reservoir[j] = currNode;
  //     return reservoir[j]->val;
  //   }
  //   return reservoir[j % k]->val;
  // }
  int getRandom() {
    int result = 0;
    int i = 0;

    ListNode* curr = listHead;

    while (curr) {
      i++;
      if (getRandomNumber(i) == 0) {
        result = curr->val;
      }
      curr = curr->next;
    }

    return result;
  }
};

ListNode* createList(std::vector<int> vals) {
  if (vals.empty()) return nullptr;
  ListNode* head = new ListNode(vals[0]);
  ListNode* curr = head;
  for (size_t i = 1; i < vals.size(); i++) {
    curr->next = new ListNode(vals[i]);
    curr = curr->next;
  }
  return head;
}

void printPass(int testNum) { std::cout << "\033[32mTest " << testNum << " Passed \033[0m\n"; }
void printFail(int testNum) { std::cout << "\033[31mTest " << testNum << " Failed \033[0m\n"; }

int main() {
  {
    auto head = createList({10});
    ReservoirSampler rs(head, 1);
    bool ok = true;

    for (int i = 0; i < 10; i++) {
      if (rs.getRandom() != 10) {
        ok = false;
        break;
      }
    }

    ok ? printPass(1) : printFail(1);
  }

  {
    auto head = createList({1, 2, 3, 4, 5});
    ReservoirSampler rs(head, 1);
    bool ok = true;

    for (int i = 0; i < 20; i++) {
      int val = rs.getRandom();
      if (val < 1 || val > 5) {
        ok = false;
        break;
      }
    }

    ok ? printPass(2) : printFail(2);
  }

  {
    auto head = createList({1, 2, 3, 4});
    ReservoirSampler rs(head, 2);
    bool ok = true;

    for (int i = 0; i < 20; i++) {
      int val = rs.getRandom();
      if (val < 1 || val > 4) {
        ok = false;
        break;
      }
    }

    ok ? printPass(3) : printFail(3);
  }

  {
    auto head = createList({7, 8, 9});
    ReservoirSampler rs(head, 3);
    bool ok = true;

    for (int i = 0; i < 20; i++) {
      int val = rs.getRandom();
      if (!(val == 7 || val == 8 || val == 9)) {
        ok = false;
        break;
      }
    }

    ok ? printPass(4) : printFail(4);
  }

  {
    auto head = createList({1, 2});
    ReservoirSampler rs(head, 5);
    bool ok = true;

    for (int i = 0; i < 10; i++) {
      int val = rs.getRandom();
      if (!(val == 1 || val == 2)) {
        ok = false;
        break;
      }
    }

    ok ? printPass(5) : printFail(5);
  }

  return 0;
}
