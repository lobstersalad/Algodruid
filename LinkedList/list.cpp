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

// Basic operations

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

void list::pushPos(int value, int index) {
  if (index == 0) {
    pushFront(value);
    return;
  } else if (index == size) {
    pushBack(value);
    return;
  } else if (index > 0 && index > size) {
    cout << "No such index" << endl;
    return;
  } else {
    cout << "Inserting " << value << " at index " << index << endl;
  }
  node *previous;
  node *current = head;
  node *temp = new node;
  temp->data = value;
  for (int i = 0; i < index; i++) {
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

void list::popPos(int index) {
  if (size > 0) {
    if (index == 0) {
      popFront();
      return;
    } else if (index == size - 1) {
      popBack();
      return;
    } else if (index > 0 && index >= size) {
      cout << "No such index" << endl;
      return;
    } else {
      cout << "Popping index " << index << endl;
    }
    node *previous;
    node *current = head;
    for (int i = 0; i < index; i++) {
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

void list::clear() {
  while (size > 0) {
    node *temp = head;
    head = head->next;
    delete temp;
    size--;
  }
}

int list::getSize() {
  return size;
}

// Special operations

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
  if (k > 1 && k < size) {
    cout << "Reversing every " << k << " nodes in the list" << endl;
    bool head_set = false;
    int counter = 0;
    node *temp = NULL;
    node *marker = NULL;
    node *previous = NULL;
    node *current = head;
    while (current != NULL) {
      if (counter == k) {
        if (head_set == false) {
          head = previous;
          head_set = true;
        }
        if (marker != NULL) {
          marker->next = previous;
        }
        while (previous->next != NULL) {
          previous = previous->next;
        }
        marker = previous;
        previous = NULL;
        counter = 0;
      }
      if (current != NULL) {
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
    while (current != NULL) {
      current = current->next;
      position = position->next;
    }
    cout << "Value at position " << k << " from the end is " << position->data << endl;
  } else {
    cout << "No such position" << endl;
  }
}
