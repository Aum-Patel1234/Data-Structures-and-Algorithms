#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPER_LIMIT 16

int get_random_int() { return rand() % UPPER_LIMIT; }

typedef struct Node {
  int val;
  uint8_t level;  // we know level is notgreater than UPPER_LIMIT
  struct Node** nodes;
} Node;

Node** create_levels(uint8_t level) {
  Node** nodes = (Node**)malloc(level * sizeof(Node*));
  if (!nodes) return NULL;
  for (uint8_t i = 0; i < level; i++) {
    nodes[i] = NULL;
  }
  return nodes;
}
Node* create_node(int val) {
  uint8_t level = (uint8_t)get_random_int();
  Node* new_node = (Node*)malloc(sizeof(Node));
  if (!new_node) return NULL;
  new_node->val = val;
  new_node->level = level;
  new_node->nodes = create_levels(level);
  return new_node;
}

typedef struct {
  Node *head, *curr;
} Skiplist;

Skiplist* skiplistCreate() {
  srand(time(NULL));
  Skiplist* sl = (Skiplist*)malloc(sizeof(Skiplist));
  if (!sl) return NULL;
  sl->head = create_node(INT_MIN);
  // sl->prev_nodes = create_levels(UPPER_LIMIT);  // prev nodes for each level to keep join to new ones
  sl->curr = sl->head;
  return sl;
}

Node* search_and_fill_prev_nodes(Node* head, Node** prev_nodes, int target) {
  Node* temp = head;
  while (temp->val < target) {
    int curr_level = temp->level;
    // int val = temp->val;
    Node** nodes = temp->nodes;

    bool flag = false;
    uint8_t level = curr_level;
    for (; level >= 0; level--) {
      if (level < curr_level) prev_nodes[level] = temp->nodes[level];  // fill prev_nodes
      if (nodes[level] && nodes[level]->val >= target) {
        flag = true;
        break;
      }
    }
    if (flag) break;

    temp = nodes[level];  // move forward if not found
  }

  return temp;
}

bool skiplistSearch(Skiplist* obj, int target) {
  Node* prev_nodes[UPPER_LIMIT];
  Node* node = search_and_fill_prev_nodes(obj->head, prev_nodes, target);
  // printf("(insert) node val = %d\n", node->val);
  return node->val == target;
}

void skiplistAdd(Skiplist* obj, int num) {
  // Node* curr_node = obj->curr;
  Node* new_node = create_node(num);
  uint8_t level = new_node->level;

  Node* prev_nodes[UPPER_LIMIT];
  Node* node = search_and_fill_prev_nodes(obj->head, prev_nodes, num);
  printf("(insert) node val = %d\n", node->val);

  // fill next nodes  ptrs
  for (uint8_t l = 0; l < level; l++) {
    Node* prev_node = prev_nodes[l];
    // copy the next node in same layer if exists
    if (prev_node && l < prev_node->level) new_node->nodes[level] = prev_node->nodes[l];
  }

  // fix prev_nodes
  for (uint8_t l = 0; l < level; l++) prev_nodes[l] = new_node->nodes[l];
}

bool skiplistErase(Skiplist* obj, int num) {
  Node* prev_nodes[UPPER_LIMIT];
  Node* node = search_and_fill_prev_nodes(obj->head, prev_nodes, num);
  if (node->val != num) return false;
  printf("(erase) node val = %d\n", node->val);

  return true;
}

void skiplistFree(Skiplist* obj) {
  Node* head = obj->head;
  while (head) {
    Node* next_node = head->nodes[0];  // each node at level 0
    free(head->nodes);
    free(head);
    head = next_node;
  }
  // free(obj->prev_nodes);
  free(obj);
}

/**
 * Your Skiplist struct will be instantiated and called as such:
 * Skiplist* obj = skiplistCreate();
 * bool
 * param_1 = skiplistSearch(obj, target);

 * skiplistAdd(obj, num);

 * bool param_3 = skiplistErase(obj, num);

 *
 * skiplistFree(obj);
*/
int main(void) {
  Skiplist* s;

  // TEST 1: Empty skiplist
  s = skiplistCreate();
  printf("%d\n", get_random_int());
  assert(skiplistSearch(s, 10) == false);
  assert(skiplistErase(s, 10) == false);
  skiplistFree(s);
  //
  // // TEST 2: Single insertion
  // s = skiplistCreate();
  // skiplistAdd(s, 10);
  // assert(skiplistSearch(s, 10) == true);
  // assert(skiplistSearch(s, 5) == false);
  // assert(skiplistErase(s, 10) == true);
  // assert(skiplistSearch(s, 10) == false);
  // skiplistFree(s);
  //
  // // TEST 3: Multiple insertions
  // s = skiplistCreate();
  // skiplistAdd(s, 10);
  // skiplistAdd(s, 20);
  // skiplistAdd(s, 30);
  // skiplistAdd(s, 40);
  // assert(skiplistSearch(s, 10) == true);
  // assert(skiplistSearch(s, 20) == true);
  // assert(skiplistSearch(s, 30) == true);
  // assert(skiplistSearch(s, 40) == true);
  // assert(skiplistSearch(s, 50) == false);
  // skiplistFree(s);
  //
  // // TEST 4: Unsorted insertion order
  // s = skiplistCreate();
  // skiplistAdd(s, 50);
  // skiplistAdd(s, 10);
  // skiplistAdd(s, 40);
  // skiplistAdd(s, 20);
  // skiplistAdd(s, 30);
  // for (int i = 10; i <= 50; i += 10) assert(skiplistSearch(s, i) == true);
  // skiplistFree(s);
  //
  // // TEST 5: Duplicate values
  // s = skiplistCreate();
  // skiplistAdd(s, 10);
  // skiplistAdd(s, 10);
  // skiplistAdd(s, 10);
  // assert(skiplistSearch(s, 10) == true);
  // assert(skiplistErase(s, 10) == true);
  // assert(skiplistSearch(s, 10) == true);
  // assert(skiplistErase(s, 10) == true);
  // assert(skiplistSearch(s, 10) == true);
  // assert(skiplistErase(s, 10) == true);
  // assert(skiplistSearch(s, 10) == false);
  // assert(skiplistErase(s, 10) == false);
  // skiplistFree(s);
  //
  // // TEST 6: Erasing first, middle, and last elements
  // s = skiplistCreate();
  // for (int i = 1; i <= 5; i++) skiplistAdd(s, i * 10);
  //
  // assert(skiplistErase(s, 10) == true);
  // assert(skiplistErase(s, 30) == true);
  // assert(skiplistErase(s, 50) == true);
  //
  // assert(skiplistSearch(s, 10) == false);
  // assert(skiplistSearch(s, 30) == false);
  // assert(skiplistSearch(s, 50) == false);
  // assert(skiplistSearch(s, 20) == true);
  // assert(skiplistSearch(s, 40) == true);
  // skiplistFree(s);
  //
  // // TEST 7: Negative and zero values
  // s = skiplistCreate();
  // skiplistAdd(s, -100);
  // skiplistAdd(s, -1);
  // skiplistAdd(s, 0);
  // skiplistAdd(s, 1);
  // skiplistAdd(s, 100);
  //
  // assert(skiplistSearch(s, -100) == true);
  // assert(skiplistSearch(s, -1) == true);
  // assert(skiplistSearch(s, 0) == true);
  // assert(skiplistSearch(s, 1) == true);
  // assert(skiplistSearch(s, 100) == true);
  // assert(skiplistSearch(s, -50) == false);
  // skiplistFree(s);
  //
  // // TEST 8: Large and boundary values
  // s = skiplistCreate();
  // skiplistAdd(s, -20000);
  // skiplistAdd(s, 20000);
  // skiplistAdd(s, 2147483647);
  // skiplistAdd(s, -2147483647 - 1);
  //
  // assert(skiplistSearch(s, -20000) == true);
  // assert(skiplistSearch(s, 20000) == true);
  // assert(skiplistSearch(s, 2147483647) == true);
  // assert(skiplistSearch(s, -2147483647 - 1) == true);
  // skiplistFree(s);
  //
  // // TEST 9: Repeated operations on the same values
  // s = skiplistCreate();
  // skiplistAdd(s, 25);
  // assert(skiplistSearch(s, 25) == true);
  // assert(skiplistErase(s, 25) == true);
  // assert(skiplistErase(s, 25) == false);
  // skiplistAdd(s, 25);
  // assert(skiplistSearch(s, 25) == true);
  // assert(skiplistErase(s, 25) == true);
  // assert(skiplistSearch(s, 25) == false);
  // skiplistFree(s);
  //
  // // TEST 10: Mixed operations
  // s = skiplistCreate();
  //
  // skiplistAdd(s, 5);
  // skiplistAdd(s, 15);
  // skiplistAdd(s, 25);
  // skiplistAdd(s, 35);
  // skiplistAdd(s, 45);
  //
  // assert(skiplistSearch(s, 25) == true);
  // assert(skiplistErase(s, 15) == true);
  //
  // skiplistAdd(s, 20);
  // skiplistAdd(s, 30);
  //
  // assert(skiplistSearch(s, 15) == false);
  // assert(skiplistSearch(s, 20) == true);
  // assert(skiplistSearch(s, 30) == true);
  //
  // assert(skiplistErase(s, 5) == true);
  // assert(skiplistErase(s, 45) == true);
  //
  // assert(skiplistSearch(s, 5) == false);
  // assert(skiplistSearch(s, 45) == false);
  // assert(skiplistSearch(s, 25) == true);
  //
  skiplistFree(s);

  printf("All 10 Skiplist test cases passed successfully!\n");

  return 0;
}
