#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {

  cout << "Welcome to Stacks and Queues" << endl;
  stack<int> int_stack;
  int_stack.push(1);
  int_stack.push(2);
  int_stack.push(3);

  return 0;
}
