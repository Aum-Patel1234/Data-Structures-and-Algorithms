#pragma once

#include <string>
#include <vector>
#ifndef MAIN_HPP
#define MAIN_HPP

// ---------------- Stack ----------------
class Stack {
private:
  int *arr;
  int size;
  int capacity;

public:
  Stack();
  ~Stack();

  void push(int x);
  int pop();
  bool empty() const;
  int top() const;
};

// ---------------- MyQueue ----------------
class MyQueue {
private:
  int *arr;
  int front;
  int rear;
  int capacity;

public:
  MyQueue();
  ~MyQueue();

  void push(int val);
  int pop();
  int size() const;
  bool empty() const;
};

// ---------------- LinkedList ----------------
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int v);
};

class LinkedList {
private:
  ListNode *head;

public:
  LinkedList();
  ~LinkedList();

  void insertFront(int x);
  void insertBack(int x);
  void insertAt(int pos, int x);

  void removeFront();
  void removeBack();
  void removeAt(int pos);

  int search(int x);
  void reverse();
  int length();
  void display();
};

// ---------------- Deque ----------------
struct DequeNode {
  int val;
  DequeNode *prev;
  DequeNode *next;
  DequeNode(int v);
};

class Deque {
private:
  DequeNode *front;
  DequeNode *back;
  int size;

public:
  Deque();
  ~Deque();

  void pushFront(int x);
  void pushBack(int x);

  void popFront();
  void popBack();

  int getFront();
  int getBack();

  bool isEmpty();
  int getSize();
  void clear();
  void display();
  std::vector<int> toVector();
};

// ---------------- Trie ----------------
struct TrieNode {
  TrieNode *children[26]; // Fixed size for 'a' to 'z'
  bool flag;

  TrieNode *assign(int idx);
  bool isEnd();
  TrieNode *get(int idx);
  void setEnd(bool v);
  TrieNode();
};
class Trie {
private:
  TrieNode *root;

public:
  Trie();
  ~Trie();

  void insert(const std::string &word);
  bool search(const std::string &word) const;
  bool startsWith(const std::string &prefix) const;
  // TODO:
  // bool remove(const std::string &word);
};
#endif // MAIN_HPP
