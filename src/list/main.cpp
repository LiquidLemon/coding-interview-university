#include <iostream>
#include "List.hpp"

using namespace std;

int main() {
  List<int> list;
  list.pushFront(1);
  list.pushFront(2);
  list.pushFront(3);
  cout << list.size() << endl;
  cout << list.popFront() << endl;
  cout << list.popFront() << endl;
  cout << list.popFront() << endl;
  return 0;
}
