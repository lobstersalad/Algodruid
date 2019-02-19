#include "list.h"

using std::cin;

int MainMenu() {
  int option = 0;
  cout << "Main Menu:" << endl;
  cout << "1. Basic Operations" << endl;
  cout << "2. Special Operations" << endl;
  cout << "3. Exit" << endl;
  cin >> option;
  return option;
}

int BasicMenu() {
  int option = 0;
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
  return option;
}

int SpecialMenu() {

}

int main() {

  list my_list;

  int option = 0, value = 0, position = 0;

  cout << "Main Menu:" << endl;
  cout << "1. Basic Operations" << endl;
  cout << "2. Special Operations" << endl;
  cout << "3. Exit" << endl;
  cin >> option;

  do {
    if (option == 1) {
      option = BasicMenu();
      do {
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
          cout << "Popping" << endl;
          my_list.popFront();
        } else if (option == 5) {
          cout << "Popping" << endl;
          my_list.popBack();
        } else if (option == 6) {
          cout << "Enter position" << endl;
          cin >> position;
          my_list.popPos(position);
        } else if (option == 7) {
          my_list.display();
        } else if (option == 8) {
          cout << "Returning to Main Menu" << endl;
        }
        option = BasicMenu();
      } while (option != 8);
    } else if (option == 2) {
      option = SpecialMenu();
    } else if (option == 3) {
    } else {
      option = MainMenu();
    }
  } while (option != 3);

  cout << "Goodbye" << endl;
  return 0;
}
