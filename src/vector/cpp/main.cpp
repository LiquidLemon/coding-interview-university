#include <iostream>
#include "Vector.hpp"

using namespace std;

template <typename T>
void print(Vector<T> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << endl;
}

int main() {
  Vector<int> vec;
  vec.push(1);
  vec.push(2);
  vec.push(3);
  vec.push(4);

  print(vec);

  cout << vec.pop() << endl;
  print(vec);

  vec.delete_at(1);
  print(vec);

  vec.insert(1, 5);
  print(vec);

  vec.prepend(0);
  print(vec);

  cout << vec.find(5) << endl;
  cout << vec.find(10) << endl;

  vec.push(5);
  vec.remove(5);
  print(vec);
}
