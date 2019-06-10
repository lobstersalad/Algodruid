#include "list.h"

list::list() : name("default"), size(0), head(nullptr) {

}

list::list(const list& copy) : name("default"), size(0), head(nullptr) {
  node *current = copy.head;
  while (current != nullptr) {
    this->pushBack(current->data);
    current = current->next;
  }
}

list& list::operator=(const list& copy) {
  list temp(copy);
  swap(head, temp.head);
  return *this;
}

list::~list() {
  if (head != nullptr) {
    node *current = head;
    while (current != nullptr) {
      node *next = current->next;
      delete current;
      current = next;
    }
  }
}

// Utility functions

void list::setName(string name) {
  this->name = name;
}

string list::getName() {
  return name;
}

int list::getSize() {
  return size;
}

node* list::goTo(int position) {
  node *current = head;
  for (int i = 0; i < position - 1; i++) {
    current = current->next;
  }
  return current;
}

node* list::goToTail() {
  node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  return current;
}

// Basic operations

void list::pushFront(char value) {
  cout << "Pushing " << value << " to the front" << endl;
  node *temp = new node;
  temp->data = value;
  temp->next = head;
  head = temp;
  size++;
}

void list::pushBack(char value) {
  cout << "Pushing " << value << " to the back" << endl;
  node *temp = new node;
  temp->data = value;
  temp->next = nullptr;
  if (head == nullptr) {
    head = temp;
    temp = nullptr;
  } else {
    node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = temp;
  }
  size++;
}

void list::pushPos(char value, int position) {
  if (position <= 1) {
    pushFront(value);
    return;
  } else if (position >= size) {
    pushBack(value);
    return;
  } else {
    cout << "Inserting " << value << " at position " << position << endl;
  }
  node *previous;
  node *current = head;
  node *temp = new node;
  temp->data = value;
  for (int i = 0; i < position - 1; i++) {
    previous = current;
    current = current->next;
  }
  previous->next = temp;
  temp->next = current;
  size++;
}

void list::popFront() {
  if (size > 0) {
    cout << "Popping node at the front" << endl;
    node *temp = head;
    head = head->next;
    delete temp;
    size--;
  } else {
    cout << "List is already empty" << endl;
  }
}

void list::popBack() {
  if (size > 1) {
    cout << "Popping node at the back" << endl;
    node *previous;
    node *current = head;
    while (current->next != nullptr) {
      previous = current;
      current = current->next;
    }
    previous->next = nullptr;
    delete current;
    size--;
  } else if (size == 1) {
    popFront();
  } else {
    cout << "List is already empty" << endl;
  }
}

void list::popPos(int position) {
  if (size > 0) {
    if (position <= 1) {
      popFront();
      return;
    } else if (position >= size) {
      popBack();
      return;
    } else {
      cout << "Popping at position " << position << endl;
    }
    node *previous;
    node *current = head;
    for (int i = 0; i < position - 1; i++) {
      previous = current;
      current = current->next;
    }
    previous->next = current->next;
    delete current;
    size--;
  } else {
    cout << "List is already empty" << endl;
  }
}

void list::display() {
  cout << "Name: " << getName() << ", Size: " << getSize() << endl;
  if (getSize() > 0) {
    node *current = head;
    while (current->next != nullptr) {
      cout << "{" << current->data << "}->";
      current = current->next;
    }
    cout << "{" << current->data << "}" << endl;
  } else {
    cout << "List is empty" << endl;
  }
}

void list::clear() {
  while (size > 0) {
    node *temp = head;
    head = head->next;
    delete temp;
    size--;
  }
}

// Special operations

void list::reverse() {
  cout << "Reversing list" << endl;
  node *temp = nullptr;
  node *previous = nullptr;
  node *current = head;
  while (current != nullptr) {
    temp = current->next;
    current->next = previous;
    previous = current;
    current = temp;
  }
  head = previous;
}

// Non-recursive reverseK
void list::reverseK(int k) {
  if (k > 1 && k < size) {
    cout << "Reversing every " << k << " nodes in the list" << endl;
    bool head_set = false;
    int counter = 0;
    node *temp = nullptr;
    node *marker = nullptr;
    node *previous = nullptr;
    node *current = head;
    while (current != nullptr) {
      if (counter == k) {
        if (head_set == false) {
          head = previous;
          head_set = true;
        }
        if (marker != nullptr) {
          marker->next = previous;
        }
        while (previous->next != nullptr) {
          previous = previous->next;
        }
        marker = previous;
        previous = nullptr;
        counter = 0;
      }
      if (current != nullptr) {
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
        counter++;
      } else {
        // done
      }
    }
    marker->next = previous;
  } else if (k > 1 && k >= size) {
    reverse();
  } else if (k == 1) {
    cout << "No effect" << endl;
  } else {
    cout << "K should be greater than 1" << endl;
  }
}

void list::findKBegin(int k) {
  if (k >= 0 && k < size) {
    node *current = head;
    for (int i = 0; i != k; i++) {
      current = current->next;
    }
    cout << "Value at position " << k << " from the start is " << current->data << endl;
  } else {
    cout << "No such position" << endl;
  }
}

void list::findKEnd(int k) {
  if (k >= 0 && k < size) {
    node *current = head;
    node *position = head;
    for (int i = 0; i != k; i++) {
      current = current->next;
    }
    while (current != nullptr) {
      current = current->next;
      position = position->next;
    }
    cout << "Value at position " << k << " from the end is " << position->data << endl;
  } else {
    cout << "No such position" << endl;
  }
}

// Test
