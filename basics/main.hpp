#pragma once

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
#endif // MAIN_HPP
