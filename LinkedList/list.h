#include <iostream>

using std::cout;
using std::endl;

class node {
  int data;
  node *next;
};

class list {
  public:
    list();
    ~list();
    void pushFront(int value);
    void pushBack(int value);
    void pushMiddle(int value);
    void popFront();
    void popBack();
    void popMiddle();
    void display();
  private:
    node *head;
    node *tail;
};
