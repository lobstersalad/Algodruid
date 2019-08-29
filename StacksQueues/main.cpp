#include "stack.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {

  cout << "Welcome to Stacks and Queues" << endl;
  stack<int> A;
  A.push(1);
  A.push(2);
  A.push(3);
  A.display();
  stack<int> B;
  //B = A;
  B.display();

  return 0;
}
