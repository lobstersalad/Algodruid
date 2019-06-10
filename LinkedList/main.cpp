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
  while (!isdigit(option) && (option <= 0 || option > max_options)) {
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
			list.display();
    } else if (option == 2) {
      cout << "Enter k" << endl;
      cin >> k;
      list.reverseK(k);
			list.display();
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
  int option = 0, max_options = 9, position;
	char value;
  do {
    cout << "Basic Menu:" << endl;
    cout << "1. Push Front" << endl;
    cout << "2. Push Back" << endl;
    cout << "3. Push to Position" << endl;
    cout << "4. Pop Front" << endl;
    cout << "5. Pop Back" << endl;
    cout << "6. Pop at Position" << endl;
    cout << "7. Display List" << endl;
    cout << "8. Clear List" << endl;
    cout << "9. Back" << endl;
    option = parseOption(max_options);
    if (option == 1) {
      cout << "Enter value" << endl;
      cin >> value;
      list.pushFront(value);
			list.display();
    } else if (option == 2) {
      cout << "Enter value" << endl;
      cin >> value;
      list.pushBack(value);
			list.display();
    } else if (option == 3) {
      cout << "Enter value and position" << endl;
      cin >> value >> position;
      list.pushPos(value, position);
			list.display();
    } else if (option == 4) {
      list.popFront();
			list.display();
    } else if (option == 5) {
      list.popBack();
			list.display();
    } else if (option == 6) {
      cout << "Enter position" << endl;
      cin >> position;
      list.popPos(position);
			list.display();
    } else if (option == 7) {
      list.display();
    } else if (option == 8) {
      list.clear();
    } else if (option == max_options) {
      cout << "Returning to main menu" << endl;
    }
  } while (option != max_options);
}

list selectList(lists &lists) {

}

void listManager(lists &lists) {
	int option = 0, max_options = 5;
	do {
		cout << "List Manager:" << endl;
		cout << "1. New List" << endl;
		cout << "2. Delete List" << endl;
		cout << "3. Copy List" << endl;
		cout << "4. Display Lists" << endl;
		cout << "5. Back" << endl;
		option = parseOption(max_options);
		if (option == 1) {
			lists.newList();
		} else if (option == 2) {
			lists.deleteList();
		} else if (option == 3) {
			lists.copyList();
		} else if (option == 4) {
			lists.display();
		} else if (option == max_options) {
			cout << "Returning to main menu" << endl;
		}
	} while (option != max_options);
}

void mainMenu(lists &lists) {
  int option = 0, max_options = 4;
	list current;
  do {
    cout << "Main Menu:" << endl;
		// Current List Display
		cout << "1. List Manager" << endl;
    cout << "2. Basic Operations" << endl;
    cout << "3. Special Operations" << endl;
    cout << "4. Exit" << endl;
    option = parseOption(max_options);
		if (option == 1) {
			listManager(lists);
		} else if (option == 2) {
			cout << "On which list would you like to perform basic operations?" << endl;
			for (int i = 0; i < lists.list_storage.size(); i++) {
				cout << i + 1 << ". " << lists.list_storage[i]->getName() << endl;
			}
			option = parseOption(lists.list_storage.size());
      basicMenu(*lists.list_storage[option - 1]);
    } else if (option == 3) {
			cout << "On which list would you like to perform special operations?" << endl;
			for (int i = 0; i < lists.list_storage.size(); i++) {
				cout << i + 1 << ". " << lists.list_storage[i]->getName() << endl;
			}
			option = parseOption(lists.list_storage.size());
			specialMenu(*lists.list_storage[option - 1]);
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
