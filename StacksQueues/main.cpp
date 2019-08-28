#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {

  cout << "Welcome to Stacks and Queues" << endl;
  stack<int> int_stack;
  int_stack.push(2);
  cout << "Top of the stack is now: " << int_stack.get_top() << endl;
  int_stack.push(1);
  cout << "Top of the stack is now: " << int_stack.get_top() << endl;

  return 0;
}
