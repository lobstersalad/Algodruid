#include <iostream>

using std::cout;
using std::endl;

class node {
  public:
    int data;
    node *next = NULL;
};

class list {
  public:
    list();
    ~list();
    void pushFront(int value);
    void pushBack(int value);
    void pushPos(int value, int position);
    void popFront();
    void popBack();
    void popPos(int position);
    void display();
    int getSize();
  private:
    node *head;
    int size = 0;
};
