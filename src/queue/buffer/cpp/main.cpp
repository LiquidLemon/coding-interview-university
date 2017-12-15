#include <iostream>
#include <exception>
#include "Queue.hpp"

using namespace std;

int main() {
  Queue<int> q(4);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  cout << q.dequeue() << endl;
  q.enqueue(4);
  q.enqueue(5);
  try {
    q.enqueue(6);
  } catch (exception &e) {
    cout << e.what() << endl;
  }
  while (!q.empty()) {
    cout << q.dequeue() << endl;
  }
  try {
    q.dequeue();
  } catch (exception& e) {
    cout << e.what() << endl;
  }
  return 0;
}
