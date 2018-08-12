#include <iostream>
#include "Map.hpp"

using namespace std;

int main() {
  Map<int> map(101);
  cout << map.add("Foo", 1) << endl;
  cout << map.add("Foo", 2) << endl;
  map.add("Bar", 3);
  cout << map.exists("Foo") << endl;
  cout << map.exists("Bar") << endl;
  map.remove("Bar");
  cout << map.exists("Bar") << endl;
  cout << map.exists("Baz") << endl;
  cout << map.get("Foo") << endl;
  cout << map.get("Bar") << endl;
  cout << map.get("Baz") << endl;
  return 0;
}
