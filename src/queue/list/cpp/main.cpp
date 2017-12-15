#include <iostream>
#include "Queue.hpp"

using namespace std;

int main() {
  Queue<int> q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  cout << q.dequeue() << endl;
  q.enqueue(4);
  q.enqueue(5);
  while (!q.empty()) {
    cout << q.dequeue() << endl;
  }
  return 0;
}
