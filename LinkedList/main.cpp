#include "list.h"

using std::cin;

void SpecialMenu(list &my_list) {
  int option = 0;
  do {
    cout << "Special Menu:" << endl;
    cout << "1. Reverse List" << endl;
    cout << "2. Back" << endl;
    cin >> option;
    if (option == 1) {
      my_list.reverse();
    } else if (option == 2) {
      cout << "Returning to main menu" << endl;
    } else {
      cout << "Invalid option" << endl;
    }
  } while (option != 2);
}

void BasicMenu(list &my_list) {
  int option = 0, value, position;
  do {
    cout << "Basic Menu:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Push to given position" << endl;
    cout << "4. Pop Front" << endl;
    cout << "5. Pop Back" << endl;
    cout << "6. Pop at given position" << endl;
    cout << "7. Display" << endl;
    cout << "8. Back" << endl;
    cin >> option;
    if (option == 1) {
      cout << "Enter value" << endl;
      cin >> value;
      my_list.pushFront(value);
    } else if (option == 2) {
      cout << "Enter value" << endl;
      cin >> value;
      my_list.pushBack(value);
    } else if (option == 3) {
      cout << "Enter value and position" << endl;
      cin >> value >> position;
      my_list.pushPos(value, position);
    } else if (option == 4) {
      my_list.popFront();
    } else if (option == 5) {
      my_list.popBack();
    } else if (option == 6) {
      cout << "Enter position" << endl;
      cin >> position;
      my_list.popPos(position);
    } else if (option == 7) {
      my_list.display();
    } else if (option == 8) {
      cout << "Goodbye" << endl;
    } else {
      cout << "Invalid option" << endl;
    }
  } while (option != 8);
}

void MainMenu(list &my_list) {
  int option = 0;
  do {
    cout << "Main Menu:" << endl;
    cout << "1. Basic Operations" << endl;
    cout << "2. Special Operations" << endl;
    cout << "3. Exit" << endl;
    cin >> option;
    if (option == 1) {
      BasicMenu(my_list);
    } else if (option == 2) {
      SpecialMenu(my_list);
    } else if (option == 3) {
      cout << "Goodbye" << endl;
    } else {
      cout << "Invalid option" << endl;
    }
  } while (option != 3);
}

int main() {

  list my_list;

  MainMenu(my_list);

  return 0;
}
