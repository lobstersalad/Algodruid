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
    stack(const stack& stack);
    //stack& operator=(const stack& stack);
    ~stack();
    void push(T value);
    T pop();
    T get_top();
};

// Class Definition

template <class T>
stack<T>::stack() : name("default"), size(0), top(nullptr) {

}

template <class T>
stack<T>::stack(const stack& stack) : name("default"), size(0), top(nullptr) {
  node *temp = copy.top;
  while (temp != nullptr) {

  }
}

template <class T>
stack& stack<T>::operator=(const stack& copy) {
  stack temp(copy);
  swap(top, temp.top);
  return *this;
}

template <class T>
stack<T>::~stack() {
  node *temp;
  while (top != nullptr) {
    temp = top;
    top = top->next;
    delete temp;
  }
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
  if (size > 0) {
    cout << "Popping top off the stack" << endl;
    T value = top->data;
    node *temp = top;
    top = top->next;
    delete temp;
    size--;
    return value;
  } else {
    cout << "Stack is empty" << endl;
  }
}

template <class T>
T stack<T>::get_top() {
  return top->data;
}

#endif
