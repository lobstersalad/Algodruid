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
    char data;
    node *next = nullptr;
};

class list {
  public:
    list();
    list(const list& list);
    list& operator=(const list& list);
    ~list();
    // Utility functions
    void setName(string name);
    string getName();
    int getSize();
    node* goTo(int position);
    // Basic operations
    void pushFront(char value);
    void pushBack(char value);
    void pushPos(char value, int position);
    void popFront();
    void popBack();
    void popPos(int position);
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
