#include <iostream>
#include <iterator>
#include <list>
#include <vector>

namespace demo1 {
void main() {
  auto items = std::vector<int>(); // empty vector

  std::cout << (items.begin() == items.end() ? "true" : "false") << std::endl;
}
} // namespace demo1

namespace demo2 {
void main() {
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
}
} // namespace demo2

namespace demo3 {

void main() {
  auto v = std::vector<int>{1, 2, 3};

  int i = 0;
  for (auto it = v.begin(); it != v.end(); ++it) {
    // iterator can be used to modify the value
    *it = i;
    ++i;
    std::cout << *it << std::endl;
  }

  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    // const iterator cannot be used to modify the value
    // *it = 0;
    std::cout << *it << std::endl;
  }

  int j = 0;
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    // reverse iterator can be used to modify the value
    *it = 0;
    ++j;
    std::cout << *it << std::endl;
  }
}
} // namespace demo3

namespace demo4 {
/**
 * @brief difference between const iterator and const_iterator
 *
 */

void main() {}

} // namespace demo4

namespace demo5 {
void main() {
  /**
   * @brief Moving back and forth with a bidirectional iterator (std::list)
   *
   */
  auto list =
      std::list<std::string>{"sator", "arepo", "tenet", "opera", "rotas"};
  auto bidirectional_it = list.begin();
  // move forward 3
  std::advance(bidirectional_it, 3);
  // move backward 2
  std::advance(bidirectional_it, -2);
  // move forward 1
  std::advance(bidirectional_it, 1);
  // move backward 2
  std::advance(bidirectional_it, -2);
  std::cout << *bidirectional_it << std::endl; // back to "sator"
}
} // namespace demo5

namespace demo6 {

/**
 * @brief difference between random access and bidirectional iterators, focusing
 * on their ability (or lack thereof) to perform direct random access on
 * elements in a container
 *
 */
void main() {
  std::vector<int> numbers_vector = {1, 2, 3, 4, 5};
  std::list<int> numbers_list = {1, 2, 3, 4, 5};

  // Random access iterator example (std::vector)
  std::vector<int>::iterator vector_it = numbers_vector.begin();

  // Directly access the 3rd element (0-indexed)
  vector_it += 2;
  std::cout << "Direct access with random access iterator (std::vector): "
            << *vector_it << std::endl; // 3

  // Bidirectional iterator example (std::list)
  std::list<int>::iterator list_it = numbers_list.begin();

  // Attempt to directly access the 3rd element (0-indexed) - not supported
  // list_it += 2; // Uncommenting this line will result in a compilation error
  // (No viable overload +=)

  // Access the 3rd element by manually incrementing the iterator
  std::advance(list_it, 2);
  std::cout << "Indirect access with bidirectional iterator (std::list): "
            << *list_it << std::endl;
}
} // namespace demo6

int main() {
  demo1::main();
  demo2::main();
  demo3::main();
  demo5::main();
  demo6::main();
}