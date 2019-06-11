#include "lists.h"

lists::lists() {

}

void lists::newList() {
  int size = 0;
  string value;
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
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed
  cin >> list_A >> list_B;
  if (list_A < 1 || list_A > list_storage.size() || list_B < 1 || list_B > list_storage.size()) {
    cout << "Invalid list" << endl;
  } else if (list_storage[list_A - 1]->getSize() == 0) {
    cout << "Copied an empty list" << endl;
  } else {
    cout << "Select target node in list A:" << endl;
    list_storage[list_A - 1]->display();
    cin >> target;
    node *current_A = list_storage[list_A - 1]->goTo(target);
    // Use of limit allows copying a list to itself
    int counter = 0, limit = list_storage[list_A - 1]->getSize() - target + 1;
    while (current_A != nullptr && counter != limit) {
      list_storage[list_B - 1]->pushBack(current_A->data);
      current_A = current_A->next;
      counter++;
    }
  }
}

void lists::display() {
  for (int i = 0; i < list_storage.size(); i++) {
    list_storage[i]->display();
    cout << endl;
  }
}
