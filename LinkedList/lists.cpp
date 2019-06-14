#include "lists.h"

lists::lists() {

}

void lists::newList() {
  int size = 0;
  string value;
  string name;
  cout << "Please enter a name for this list:" << endl;
  cin >> name;
  cout << "Please enter the size of this list:" << endl;
  cin >> size;
  auto new_list = std::make_shared<list>();
  new_list->setName(name);
  for (int i = 0; i < size; i++) {
    cout << "Enter value for node " << i + 1 << ":" << endl;
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
  cout << "Note: Because lists are not intended to be merged in this fashion, this operation will break other functions" << endl;
  cout << "Select lists A and B:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed here and for target below
  cin >> list_A >> list_B;
  if (list_A < 1 || list_A > list_storage.size() || list_B < 1 || list_B > list_storage.size()) {
    cout << "Invalid list" << endl;
  } else if (list_storage[list_A - 1]->getSize() == 0 || list_storage[list_B - 1]->getSize() == 0) {
    cout << "Cannot operate on an empty list" << endl;
  } else {
    int target;
    cout << "Select target node in list B:" << endl;
    list_storage[list_B - 1]->display();
    cin >> target;
    node *tail_A = list_storage[list_A - 1]->goTo(list_storage[list_A - 1]->getSize());
    node *current_B = list_storage[list_B - 1]->goTo(target);
    tail_A->next = current_B;
    // Update list size
    while (tail_A->next != nullptr) {
      tail_A = tail_A->next;
      list_storage[list_A - 1]->growBy(1);
    }
  }
}

void lists::findCommon() {
  int list_A, list_B;
  cout << "This operation will find the common node at which two lists merge" << endl;
  cout << "Select list A:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed
  cin >> list_A;
  cout << "Select list B:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    if (i + 1 != list_A) {
      cout << i + 1 << ". " << list_storage[i]->getName() << endl;
    } else {
      // Do nothing
    }
  }
  cin >> list_B;
  if (list_A < 1 || list_A > list_storage.size() || list_B < 1 || list_B > list_storage.size()) {
    cout << "Invalid list" << endl;
  } else if (list_A == list_B) {
    cout << "Must select two different lists" << endl;
  } else if (list_storage[list_A - 1]->getSize() == 0 || list_storage[list_B - 1]->getSize() == 0) {
    cout << "Cannot operate on an empty list" << endl;
  } else {
    int size_A = list_storage[list_A - 1]->getSize();
    int size_B = list_storage[list_B - 1]->getSize();
    // Set current_A and current_B to heads of their respective lists
    node *current_A = list_storage[list_A - 1]->goTo(1);
    node *current_B = list_storage[list_B - 1]->goTo(1);
    // Advance node pointers so that remaining node count for both lists are equal
    if (size_A > size_B) {
      for (int i = 0; i < (size_A - size_B); i++) {
        current_A = current_A->next;
      }
    } else if (size_B > size_A) {
      for (int i = 0; i < (size_B - size_A); i++) {
        current_B = current_B->next;
      }
    }
    // Advance node pointers until they are equal
    while (current_A != current_B) {
      current_A = current_A->next;
      current_B = current_B->next;
    }
    if (current_A != nullptr) {
      cout << "Lists merge at " << current_A->data << endl;
    } else {
      cout << "No common node found" << endl;
    }
  }
}

void lists::mirror() {
  int option, counter;
  cout << "This operation will append the first n - 1 nodes of a list onto the end of itself" << endl;
  cout << "Select list to mirror:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  cin >> option;
  node *current_A = list_storage[option - 1]->goTo(1)->next;
  while (current_A != nullptr) {
    list_storage[option - 1]->pushFront(current_A->data);
    current_A = current_A->next;
  }
}

void lists::interleave() {
  int list_A, list_B;
  cout << "This operation will interleave two lists. List A will be renamed and list B will be destroyed" << endl;
  cout << "The smaller list will always be integrated into the larger list" << endl;
  cout << "Select list A:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    cout << i + 1 << ". " << list_storage[i]->getName() << endl;
  }
  // Input validation needed
  cin >> list_A;
  cout << "Select list B:" << endl;
  for (int i = 0; i < list_storage.size(); i++) {
    if (i + 1 != list_A) {
      cout << i + 1 << ". " << list_storage[i]->getName() << endl;
    } else {
      // Do nothing
    }
  }
  cin >> list_B;
  if (list_A < 1 || list_A > list_storage.size() || list_B < 1 || list_B > list_storage.size()) {
    cout << "Invalid list" << endl;
  } else if (list_A == list_B) {
    cout << "Cannot interleave a list with itself" << endl;
  } else if (list_storage[list_A - 1]->getSize() == 0 || list_storage[list_B - 1]->getSize() == 0) {
    cout << "Cannot operate on an empty list" << endl;
  } else {
    // List A must be the larger list
    if (list_storage[list_A - 1]->getSize() >= list_storage[list_B - 1]->getSize()) {
      // Proceed
    } else {
      // Swap lists before proceeding
      int temp = list_A;
      list_A = list_B;
      list_B = temp;
    }
    // Interleave
    node *current_A = list_storage[list_A - 1]->goTo(1);
    node *current_B = list_storage[list_B - 1]->goTo(1);
    node *temp_A = current_A->next, *temp_B = current_B->next;
    while (current_A != nullptr && current_B != nullptr) {
      current_A->next = current_B;
      current_A = temp_A;
      current_B->next = current_A;
      current_B = temp_B;
      if (current_A != nullptr) {
        temp_A = current_A->next;
      }
      if (current_B != nullptr) {
        temp_B = current_B->next;
      }
    }
    // Rename list A and update its size; erase list B
    string name;
    cout << "Please enter a name for the new list" << endl;
    cin >> name;
    list_storage[list_A - 1]->setName(name);
    list_storage[list_A - 1]->growBy(list_storage[list_B - 1]->getSize());
    list_storage[list_B - 1]->nullifyHead();
    list_storage.erase(list_storage.begin() + list_B - 1);
  }
}

void lists::display() {
  for (int i = 0; i < list_storage.size(); i++) {
    list_storage[i]->display();
    cout << endl;
  }
}
