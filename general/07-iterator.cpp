#include <iostream>
#include <iterator>
#include <vector>

int main() {
  auto v = std::vector<int>{1, 2, 3};
  // const auto cv = v;

  // vector<int>'s non-const iterator
  ++(v.begin());
  // vector<int>'s const iterator
  // *cv.begin();
  // vector<int>'s const iterator
  v.cbegin();

  auto it = v.begin();
  std::cout << *it++ << " " << *it++ << " " << *it++ << " " << *it++ << " "
            << *it++ << " " << *it++ << " " << std::endl;
  std::cout << *--it << " " << *--it << " " << *--it << " " << *--it << " "
            << *--it << " " << *--it << " " << *--it << " " << *++it << " "
            << *++it << " " << *++it << " " << std::endl;

  auto it2 = v.begin();
  std::advance(it2, 3);
  std::cout << *it2 << std::endl;
  std::cout << v[-2] << std::endl;

  return 0;
}
