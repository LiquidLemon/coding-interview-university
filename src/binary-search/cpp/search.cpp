#include "search.hpp"
#include <iostream>

using namespace std;

int search(int *arr, size_t start, size_t end, int value) {
  cout << "start: " << start << " end: " <<  end << endl;
  if (start < end) {
    int middle = start + (end - start) / 2;
    if (arr[middle] < value) {
      return search(arr, middle + 1, end, value);
    } else if (arr[middle] > value) {
      return search(arr, start, middle - 1, value);
    }
    return middle;
  } else {
    return -1;
  }
};
int search(int *arr, size_t n, int value) {
  return search(arr, 0, n, value);
}
