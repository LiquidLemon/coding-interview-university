#include <iostream>
#include <climits>
#include <math.h>
#include "bitwise.hpp"

using namespace std;

int main() {
  int value = 0b11001101;
  cout << countBits(value) << endl;
  cout << roundUpToPowerOf2(9) << endl;
  int a = 5;
  int b = 13;
  cout << "a: " << a << " b: " << b << endl;
  xorSwap(a, b);
  cout << "a: " << a << " b: " << b << endl;
  cout << binaryAbs(INT_MIN) << endl;
  int v = abs(INT_MIN);
  cout << v << endl;
  cout << abs(-.5) << endl;
  cout << binaryAbs(13) << endl;
  return 0;
}
