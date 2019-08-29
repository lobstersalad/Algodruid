#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::swap;

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
    friend void swap(stack<T>& first, stack<T>& second) {
      swap(first.name, second.name);
      swap(first.size, second.size);
      swap(first.top, second.top);
    }
    stack();
    stack(const stack& copy);
    stack(stack&& that);
    stack& operator=(stack copy);
    ~stack();
    void push(T value);
    T pop();
    T get_top();
    void display();
};

// Class Definition

template <class T>
stack<T>::stack() : name("default"), size(0), top(nullptr) {

}

template <class T>
stack<T>::stack(const stack& copy) : name("default"), size(0), top(nullptr) {
  cout << "Copy Constructor" << endl;
  node *temp = copy.top;
  while (temp != nullptr) {
    this->push(temp->data);
    temp = temp->next;
  }
}

template <class T>
stack<T>::stack(stack&& that) {
  swap(*this, that);
}

template <class T>
stack<T>& stack<T>::operator=(stack copy) {
  cout << "Copy Assignment" << endl;
  swap(top, copy.top);
  return *this;
}

template <class T>
stack<T>::~stack() {
  while (top != nullptr) {
    node *temp = top;
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
  if (top != nullptr) {
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

template <class T>
void stack<T>::display() {
  if (top != nullptr) {
    node *current = top;
    while (current != nullptr) {
      cout << "- " << current->data << " -" << endl;
      current = current->next;
    }
  } else {
    cout << "Stack is empty" << endl;
  }
}

#endif
