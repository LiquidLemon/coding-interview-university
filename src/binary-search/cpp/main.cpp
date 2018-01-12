#include <iostream>
#include "search.hpp"

using namespace std;

bool test() {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
  int n = sizeof(arr)/sizeof(arr[0]);
  bool valid = true;
  for (int i = 0; i < n; i++) {
    int value = arr[i];
    if (value != arr[search(arr, n, value)]) {
      valid = false;
    }
  }
  return valid;
}

int main() {
  int arr[] = { 1, 3, 5 };
  int length = sizeof(arr)/sizeof(arr[0]);
  cout << search(arr, length, 1) << endl;
  int arr2[] = { 1, 3, 5, 8 };
  int length2 = sizeof(arr2)/sizeof(arr2[0]);
  cout << search(arr2, length, 5) << endl;
  cout << test() << endl;
  return 0;
}
