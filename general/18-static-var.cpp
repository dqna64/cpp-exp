#include <iostream>

/**
 * @brief A function that creates a static variable and returns a
 * reference to it.
 * The reference is valid for the lifetime of the program due to the
 * variable being static.
 *
 * @return int&
 */

auto generate() -> int & {
  static int a = 5;
  return a;
}

int main() {
  int new_val = generate();
  std::cout << new_val << std::endl;
  return 0;
}