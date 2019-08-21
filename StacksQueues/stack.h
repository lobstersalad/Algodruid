#ifndef STACK_H
#define STACK_H

#include <vector>

using std::vector;

template <class T>
class node {
  public:
    typedef T value_type;
    value_type data;
    node *next = nullptr;
};

template <class T>
class stack {
  public:
    typedef node<T> node_type;
    typedef node_type* node_pointer;
    stack();
    //stack(const stack& stack);
    //stack& operator=(const stack& stack);
    //~stack();
    void push(T item);
    T pop();
  private:
    node_pointer top;
};

#endif
