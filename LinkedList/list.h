#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;
using std::endl;
using std::swap;

class node {
  public:
    int data;
    node *next = NULL;
};

class list {
  public:
    list();
    list(const list& list);
    list& operator=(const list& list);
    ~list();
    // Basic operations
    void pushFront(int value);
    void pushBack(int value);
    void pushPos(int value, int index);
    void popFront();
    void popBack();
    void popPos(int index);
    void display();
    void clear();
    int getSize();
    // Special operations
    void reverse();
    void reverseK(int k);
    void findKBegin(int k);
    void findKEnd(int k);
  private:
    node *head;
    int size = 0;
};

#endif
