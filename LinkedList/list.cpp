#include "list.h"

list::list() {
  head = NULL;
}

list::~list() {
  if (head != NULL) {
    node *current = head;
    while (current != NULL) {
      node *next = current->next;
      delete current;
      current = next;
    }
    delete head;
  }
}

void list::pushFront(int value) {
  cout << "Pushing " << value << " to the front" << endl;
  node *temp = new node;
  temp->data = value;
  temp->next = head;
  head = temp;
  size++;
}

void list::pushBack(int value) {
  cout << "Pushing " << value << " to the back" << endl;
  node *temp = new node;
  temp->data = value;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    temp = NULL;
  } else {
    node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = temp;
  }
  size++;
}

void list::pushPos(int value, int position) {
  if (position == 0) {
    pushFront(value);
    return;
  } else if (position == size) {
    pushBack(value);
    return;
  } else if (position > 0 && position > size) {
    cout << "There is no such position" << endl;
    return;
  } else {
    cout << "Inserting " << value << " at position " << position << endl;
  }
  node *previous;
  node *current = head;
  node *temp = new node;
  temp->data = value;
  for (int i = 0; i < position; i++) {
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
    while (current->next != NULL) {
      previous = current;
      current = current->next;
    }
    previous->next = NULL;
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
    if (position == 0) {
      popFront();
      return;
    } else if (position == size - 1) {
      popBack();
      return;
    } else if (position > 0 && position >= size) {
      cout << "There is no such position" << endl;
      return;
    } else {
      cout << "Popping position " << position << endl;
    }
    node *previous;
    node *current = head;
    for (int i = 0; i < position; i++) {
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
  cout << "Current size is " << getSize() << endl;
  cout << "Current list: ";
  node *current = head;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int list::getSize() {
  return size;
}

void list::reverse() {
  cout << "Reversing list" << endl;
  node *temp = NULL;
  node *previous = NULL;
  node *current = head;
  while (current != NULL) {
    temp = current->next;
    current->next = previous;
    previous = current;
    current = temp;
  }
  head = previous;
}

void list::reverseK(int k) {
  cout << "Reversing every " << k << " nodes in the list" << endl;
  int counter = 0;
  node *temp = NULL;
  node *previous = NULL;
  node *current = head;
  while (current != NULL) {
    if (counter == k) {
      current = current->next;
      k = 0;
    }
    if (current != NULL) {
      temp = current->next;
      current->next = previous;
      previous = current;
      current = temp;
      k++;
    } else {
      // done
    }
  }
}
