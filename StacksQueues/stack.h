#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

// Class Declaration

template <class T>
class stack {
  private:
    struct node {
      public:
        T data;
        node *next = nullptr;
    };
    string name;
    int size;
    node *top;
  public:
    stack();
    //stack(const stack& stack);
    //stack& operator=(const stack& stack);
    //~stack();
    void push(T value);
    T pop();
    T get_top();
};

// Class Definition

template <class T>
stack<T>::stack() : name("default"), size(0), top(nullptr) {

}

template <class T>
void stack<T>::push(T value) {
  cout << "Pushing " << value << " onto the stack" << endl;
  node *temp = new node;
  temp->data = value;
  temp->next = top;
  top = temp;
  size++;
}

template <class T>
T stack<T>::pop() {

}

template <class T>
T stack<T>::get_top() {
  return top->data;
}

#endif
