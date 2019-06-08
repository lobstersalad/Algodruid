#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::swap;
using std::string;

class node {
  public:
    int data;
    node *next = nullptr;
};

class list {
  public:
    list();
    list(const list& list);
    list& operator=(const list& list);
    ~list();
    void setName(string name);
    string getName();
    int getSize();
    // Basic operations
    void pushFront(int value);
    void pushBack(int value);
    void pushPos(int value, int index);
    void popFront();
    void popBack();
    void popPos(int index);
    void display();
    void clear();
    // Special operations
    void reverse();
    void reverseK(int k);
    void findKBegin(int k);
    void findKEnd(int k);
  private:
    string name;
    int size;
    node *head;
};

#endif
