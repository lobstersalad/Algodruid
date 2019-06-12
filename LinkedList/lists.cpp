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
  int option;
  cout << "Select list to delete:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed here
  cin >> option;
  cout << "Erased " << list_storage[option - 1]->getName() << endl;
  list_storage.erase(list_storage.begin() + option - 1);
}

void lists::copyList() {
  int list_A, list_B;
  cout << "This operation will copy list A, from target node onwards, onto the end of list B" << endl;
  cout << "Select lists A and B:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed here and for target below
  cin >> list_A >> list_B;
  if (list_A < 1 || list_A > list_storage.size() || list_B < 1 || list_B > list_storage.size()) {
    cout << "Invalid list" << endl;
  } else if (list_storage[list_A - 1]->getSize() == 0) {
    cout << "Copied an empty list" << endl;
  } else {
    int target;
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

void lists::pointList() {
  int list_A, list_B;
  cout << "This operation will point the tail of list A to a given node in list B" << endl;
  cout << "Note that this is basically an error and will break other functions" << endl;
  cout << "Selects lists A and B (must be different):" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed here and for target below
  cin >> list_A >> list_B;
  if (list_A < 1 || list_A > list_storage.size() || list_B < 1 || list_B > list_storage.size() || list_A == list_B) {
    cout << "Invalid list" << endl;
  } else if (list_storage[list_A - 1]->getSize() == 0 || list_storage[list_B - 1]->getSize() == 0) {
    cout << "Cannot select an empty list" << endl;
  } else {
    int target;
    cout << "Select target node in list B:" << endl;
    list_storage[list_B - 1]->display();
    cin >> target;
    node *tail_A = list_storage[list_A - 1]->goTo(list_storage[list_A - 1]->getSize());
    node *current_B = list_storage[list_B - 1]->goTo(target);
    tail_A->next = current_B;
    while (tail_A->next != nullptr) {
      tail_A = tail_A->next;
      list_storage[list_A - 1]->setSize(list_storage[list_A - 1]->getSize() + 1);
    }
  }
}

void lists::findCommon() {
  int list_A, list_B;
  cout << "Find the node at which two lists merge (use pointList() first)" << endl;
  cout << "Selects lists A and B (must be different):" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed here
  cin >> list_A >> list_B;
  if (list_A < 1 || list_A > list_storage.size() || list_B < 1 || list_B > list_storage.size() || list_A == list_B) {
    cout << "Invalid list" << endl;
  } else if (list_storage[list_A - 1]->getSize() == 0 || list_storage[list_B - 1]->getSize() == 0) {
    cout << "Cannot select an empty list" << endl;
  } else {
    int size_A = list_storage[list_A - 1]->getSize();
    int size_B = list_storage[list_B - 1]->getSize();
    node *current_A = list_storage[list_A - 1]->goTo(1);
    node *current_B = list_storage[list_B - 1]->goTo(1);
    if (size_A > size_B) {
      for (int i = 0; i < (size_A - size_B); i++) {
        current_A = current_A->next;
      }
    } else if (size_B > size_A) {
      for (int i = 0; i < (size_B - size_A); i++) {
        current_B = current_B->next;
      }
    }
    while (current_A != current_B) {
      current_A = current_A->next;
      current_B = current_B->next;
    }
    cout << "Lists merge at " << current_B->data << endl;
  }
}

void lists::display() {
  for (int i = 0; i < list_storage.size(); i++) {
    list_storage[i]->display();
    cout << endl;
  }
}
