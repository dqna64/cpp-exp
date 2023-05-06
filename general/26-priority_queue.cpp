#include <iostream>
#include <queue>

int main() {

  // Smallest element at top
  auto q = std::priority_queue<int, std::vector<int>, std::greater<>>{};
  q.push(8);
  q.push(3);
  q.push(5);

  std::cout << "top of priority queue: " << q.top() << std::endl; // 3

  q.pop(); // remove top element
  std::cout << "top of priority queue: " << q.top() << std::endl; // 5

  return 0;
}