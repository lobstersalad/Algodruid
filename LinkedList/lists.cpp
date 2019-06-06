#include "lists.h"

lists::lists() {

}

void lists::newList() {
  int size, value;
  cout << "Please specify size of this list" << endl;
  cin >> size;
  shared_ptr<list> new_list(new list);
  //list *new_list = new list();
  for (int i = 0; i < size; i++) {
    cout << "Enter value for node " << i + 1 << endl;
    cin >> value;
    new_list->pushBack(value);
  }
  list_storage.push_back(new_list);
  //delete new_list;
}

void lists::deleteList() {

}

void lists::display() {
  for (int i = 0; i < list_storage.size(); i++) {
    list_storage[i]->display();
  }
}
