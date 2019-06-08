#ifndef LISTS_H
#define LISTS_H

#include "list.h"
#include <vector>
#include <iostream>
#include <memory>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;

class lists {
  public:
    lists();
    void newList();
    void deleteList();
    void display();
    vector<shared_ptr<list>> list_storage;
  private:
};

#endif
