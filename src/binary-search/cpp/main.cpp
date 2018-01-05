#include <iostream>
#include "search.hpp"

using namespace std;

int main() {
  int arr[] = { 1, 3, 5 };
  int length = sizeof(arr)/sizeof(arr[0]);
  cout << search(arr, length, 1) << endl;
  cout << search(arr, length, 5) << endl;
}
