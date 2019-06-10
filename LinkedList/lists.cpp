#include "lists.h"

lists::lists() {

}

void lists::newList() {
  int size;
  char value;
  string name;
  cout << "Please enter a name for this list" << endl;
  cin >> name;
  cout << "Please enter the size of this list" << endl;
  cin >> size;
  shared_ptr<list> new_list(new list);
  new_list->setName(name);
  for (int i = 0; i < size; i++) {
    cout << "Enter value for node " << i + 1 << endl;
    cin >> value;
    new_list->pushBack(value);
  }
  list_storage.push_back(new_list);
}

void lists::deleteList() {

}

void lists::copyList() {
  int list_A, list_B, target;
  cout << "This operation will copy list A, from target node onwards, onto the end of list B" << endl;
  cout << "Example: A = {1}->{2}->{3} and B = {4}->{5}->{6}" << endl;
  cout << "Copy A to B from node 2 onwards" << endl;
  cout << "Result: A = {1}->{2}->{3} and B = {4}->{5}->{6}->{2}->{3}" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  cin >> list_A >> list_B;
  cout << "Select target node in list A:" << endl;
  list_storage[list_A - 1]->display();
  cin >> target;
  // Move to target node of list A

  // Move to tail of list B

  // While current A is not null, copy each node to B
}

void lists::display() {
  for (int i = 0; i < list_storage.size(); i++) {
    list_storage[i]->display();
    cout << endl;
  }
}
