#include <iostream>
namespace sample_1 {

// Base case: function to print a single argument
void printArgs() {}

// Variadic template function to print multiple arguments
template <typename T, typename... Args> void printArgs(T first, Args... args) {
  std::cout << first << " ";
  printArgs(args...);
}

int main() {
  int num1 = 42;
  float num2 = 3.14;
  std::string str = "Hello";

  printArgs(num1, num2, str); // Output: "42 3.14 Hello "
  std::cout << std::endl;
  printArgs(num1); // Output: "42 3.14 Hello "
  std::cout << std::endl;
  printArgs(); // Output: "42 3.14 Hello "
  std::cout << std::endl;

  return 0;
}

} // namespace sample_1

int main() {
  sample_1::main();
  return 0;
}