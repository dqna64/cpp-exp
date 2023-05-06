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
   * Note using std::advance is not the same as += 2 or -= 2 for random access
   * iterators. See demo6
   * std::list is not a random access iterator. Given it is implemetned as a
   * doubly linked list, think about why.
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

namespace demo7 {
/**
 * @brief Iterator invalidation (for vector iterator)
 *
 */

void main() {
#include <iostream>
#include <vector>

  std::vector<int> vec = {1, 2, 3, 4, 5};

  // Get an iterator to the third element (0-indexed)
  std::vector<int>::iterator it = vec.begin() + 2;

  // Print the current iterator value
  std::cout << "Before insertion: " << *it << std::endl;

  // Insert a new element at the beginning of the vector
  vec.insert(vec.begin(), 0);

  // The iterator is now invalidated due to the insertion

  // Accessing the iterator now would result in undefined behavior
  // Uncomment the following line to see the undefined behavior
  std::cout << "After insertion: " << *it << std::endl;

  // To fix the iterator invalidation, update the iterator after the insertion
  it = vec.begin() +
       3; // Adjust the iterator to point to the same element as before

  // Now the iterator is valid, and we can access its value
  std::cout << "After insertion (updated iterator): " << *it << std::endl;

  std::cout << "vector capacity: " << vec.capacity() << std::endl;
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(8);
  vec.push_back(9);
  vec.push_back(10);
  // Capacity reached, vector is reallocated, iterator invalidated
  vec.push_back(11);

  // Uncomment the following line to see the undefined behavior
  std::cout << "After reallocation: " << *it << std::endl;
}
} // namespace demo7

namespace demo8 {
/**
 * @brief iterator adaptors
 *
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2;

  std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));

  for (const auto &elem : vec2) {
    std::cout << elem << " ";
  } // 1 2 3 4 5
  std::cout << std::endl;

  // Front inserter into vec3. must be std::deque or std::list (must support
  // push_front)
  std::list<int> vec3;
  std::copy(vec1.begin(), vec1.end(), std::front_inserter(vec3));

  for (const auto &elem : vec3) {
    std::cout << elem << " ";
  } // 5 4 3 2 1
  std::cout << std::endl;

  return 0;
}

} // namespace demo8

int main() {
  demo1::main();
  demo2::main();
  demo3::main();
  demo5::main();
  demo6::main();
  demo7::main();
  demo8::main();
}