#include "lists.h"

lists::lists() {

}

void lists::newList() {
  int size, value;
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

void lists::display() {
  for (int i = 0; i < list_storage.size(); i++) {
    list_storage[i]->display();
    cout << endl;
  }
}
