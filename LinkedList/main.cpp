#include "list.h"
#include "lists.h"
#include <limits>
#include <string>

using std::cin;
using std::string;

string ordinal(int value) {
  // Find ordinal suffixes
}

int parseOption(int max_options) {
	int option;
  cin >> option;
  while (!isdigit(option) && (option < 0 || option > max_options)) {
    cout << "Invalid option" << endl;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin >> option;
  }
  return option;
}

void specialMenu(list &list) {
  int option = 0, k = 0, max_options = 6;
  do {
    cout << "Special Menu:" << endl;
    cout << "1. Reverse List" << endl;
    cout << "2. Reverse Every k Nodes" << endl;
    cout << "3. Find kth Element from Start" << endl;
    cout << "4. Find kth Element from End" << endl;
    cout << "5. Display List" << endl;
    cout << "6. Back" << endl;
    option = parseOption(max_options);
    if (option == 1) {
      list.reverse();
    } else if (option == 2) {
      cout << "Enter k" << endl;
      cin >> k;
      list.reverseK(k);
    } else if (option == 3) {
      cout << "Enter k" << endl;
      cin >> k;
      list.findKBegin(k);
    } else if (option == 4) {
      cout << "Enter k" << endl;
      cin >> k;
      list.findKEnd(k);
    } else if (option == 5) {
      list.display();
    } else if (option == max_options) {
      cout << "Returning to main menu" << endl;
    }
  } while (option != max_options);
}

void basicMenu(list &list) {
  int option = 0, max_options = 9, value, index;
  do {
    cout << "Basic Menu:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Push to Given Index" << endl;
    cout << "4. Pop Front" << endl;
    cout << "5. Pop Back" << endl;
    cout << "6. Pop at Given Index" << endl;
    cout << "7. Display List" << endl;
    cout << "8. Clear List" << endl;
    cout << "9. Back" << endl;
    option = parseOption(max_options);
    if (option == 1) {
      cout << "Enter value" << endl;
      cin >> value;
      list.pushFront(value);
    } else if (option == 2) {
      cout << "Enter value" << endl;
      cin >> value;
      list.pushBack(value);
    } else if (option == 3) {
      cout << "Enter value and index" << endl;
      cin >> value >> index;
      list.pushPos(value, index);
    } else if (option == 4) {
      list.popFront();
    } else if (option == 5) {
      list.popBack();
    } else if (option == 6) {
      cout << "Enter index" << endl;
      cin >> index;
      list.popPos(index);
    } else if (option == 7) {
      list.display();
    } else if (option == 8) {
      list.clear();
    } else if (option == max_options) {
      cout << "Returning to main menu" << endl;
    }
  } while (option != max_options);
}

void listManager(lists &lists) {
	int option = 0, max_options = 4;
	do {
		cout << "List Manager:" << endl;
		cout << "1. New List" << endl;
		cout << "2. Delete List" << endl;
		cout << "3. Display Lists" << endl;
		cout << "4. Back" << endl;
		option = parseOption(max_options);
		if (option == 1) {
			lists.newList();
		} else if (option == 2) {
			lists.deleteList();
		} else if (option == 3) {
			lists.display();
		} else if (option == max_options) {
			cout << "Returning to main menu" << endl;
		}
	} while (option != max_options);
}

void mainMenu(lists &lists) {
  int option = 0, max_options = 4;
  do {
    cout << "Main Menu:" << endl;
		cout << "1. List Manager" << endl;
    cout << "2. Basic Operations" << endl;
    cout << "3. Special Operations" << endl;
    cout << "4. Exit" << endl;
    option = parseOption(max_options);
		if (option == 1) {
			listManager(lists);
		} else if (option == 2) {
      // basicMenu();
    } else if (option == 3) {
      // specialMenu();
    } else if (option == max_options) {
      cout << "Goodbye" << endl;
    }
  } while (option != max_options);
}

int main() {

	lists lists;

  mainMenu(lists);

  return 0;
}
