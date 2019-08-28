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
    string data;
    node *next = nullptr;
};

class list {
  public:
    // Friend Swap
    friend void swap (list& first, list& second);
    // Rule of Four
    list();
    list(const list& copy);
    list(list&& that);
    list& operator=(list copy);
    ~list();
    // Utility functions
    void setName(string name);
    string getName();
    void setSize(int size);
    int getSize();
    void setHead(node *head);
    void growBy(int increase);
    node* goTo(int position);
    // Basic operations
    void pushFront(string value);
    void pushBack(string value);
    void pushPos(string value, int position);
    void popFront();
    void popBack();
    void popPos(int position);
    void display();
    void clear();
    // Special operations
    void reverse();
    node* reverse(node *start);
    void reverseK(int k);
    void findKBegin(int k);
    void findKEnd(int k);
    void mirror();
    bool isPalindrome();
  private:
    string name;
    int size;
    node *head;
};

#endif
