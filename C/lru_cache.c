#include <glib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
  int key;
  int val;
  struct LinkedList *next;
  struct LinkedList *prev;
} ll;

typedef struct {
  // GHashTable *loc; // store the loc of key in LinkedList
  struct LinkedList *head;
  struct LinkedList *tail;
  int capacity, currSize;
} LRUCache;

// IMPORTANT:we use pointer so that all the default values here will Be NULL
#define MAX_KEYS 3000
static ll *arr[MAX_KEYS];
// int* arr = malloc(3000 * sizeof(int));

LRUCache *lRUCacheCreate(int capacity) {
  LRUCache *cache = malloc(sizeof(LRUCache));
  cache->head = NULL;
  cache->tail = NULL;
  cache->currSize = 0;
  cache->capacity = capacity;
  return cache;
}
void moveToTail(LRUCache *obj, ll *node) {
  if (obj->tail == node)
    return;
  // detach node
  if (node->prev)
    node->prev->next = node->next;
  if (node->next)
    node->next->prev = node->prev;
  if (obj->head == node) // IMPORTANT:
    obj->head = node->next;

  // attach at tail
  node->prev = obj->tail;
  node->next = NULL;
  if (obj->tail)
    obj->tail->next = node;
  obj->tail = node;
}

int lRUCacheGet(LRUCache *obj, int key) {
  if (key < 0 || key >= MAX_KEYS)
    return -1;
  ll *node = arr[key];
  if (!node)
    return -1;
  moveToTail(obj, node);
  return node->val;
}

void lRUCachePut(LRUCache *obj, int key, int value) {
  if (key < 0 || key >= MAX_KEYS)
    return;
  ll *node = arr[key];

  // TRICKY below but the best
  if (node) {
    node->val = value;
    moveToTail(obj, node);
  } else {
    if (obj->currSize == obj->capacity) {
      ll *old = obj->head;
      arr[old->key] = NULL;
      obj->head = old->next;
      if (obj->head)
        obj->head->prev = NULL;
      else
        obj->tail = NULL;
      free(old);
      obj->currSize--;
    }
    ll *newNode = malloc(sizeof(ll));
    newNode->key = key;
    newNode->val = value;
    newNode->next = NULL;
    newNode->prev = obj->tail;
    if (obj->tail)
      obj->tail->next = newNode;
    obj->tail = newNode;
    if (!obj->head)
      obj->head = newNode;
    arr[key] = newNode;
    obj->currSize++;
  }
}

void lRUCacheFree(LRUCache *obj) {
  ll *head = obj->head;
  while (head) {
    ll *next = head->next;
    free(head);
    head = next;
  }
  free(obj);
}
void print(LRUCache *obj) {
  ll *head = obj->head;
  while (head) {
    printf("[%d:%d] ", head->key, head->val);
    head = head->next;
  }
}

// NOTE: A Segmentation Fault (core dumped) error occurs when your program tries
// to access memory that it’s not allowed to
int main() {
  LRUCache *lRUCache = lRUCacheCreate(2);
  lRUCachePut(lRUCache, 1, 1); // cache = {1=1}
  print(lRUCache);
  lRUCachePut(lRUCache, 2, 2); // cache = {1=1, 2=2}

  print(lRUCache);
  printf("%d\n", lRUCacheGet(lRUCache, 1)); // returns 1
  lRUCachePut(lRUCache, 3, 3);              // evicts key 2, cache = {1=1, 3=3}

  print(lRUCache);
  printf("%d\n", lRUCacheGet(lRUCache, 2)); // returns -1 (not found)
  lRUCachePut(lRUCache, 4, 4);              // evicts key 1, cache = {4=4, 3=3}

  print(lRUCache);
  printf("%d\n", lRUCacheGet(lRUCache, 1)); // returns -1 (not found)
  printf("%d\n", lRUCacheGet(lRUCache, 3)); // returns 3
  printf("%d\n", lRUCacheGet(lRUCache, 4)); // returns 4

  lRUCacheFree(lRUCache);
  return 0;
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/
