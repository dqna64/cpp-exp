#include <iostream>
#include <type_traits>

namespace demo1 {
/**
 * @brief Demonstration of SFINAE (substitution failure is not an error).
 * The function template is instantiated only if the template arguments
 * satisfy the template constraints. Otherwise a substitution failure
 * occurs and the instantiation is discarded.
 *
 */

template <typename IntegralType,
          typename = std::enable_if_t<std::is_integral<IntegralType>::value>>
auto add_integral(const IntegralType v1, const IntegralType v2) {
  return v1 + v2;
}

void main() {
  std::cout << "==== SFINAE Function Templates Demo ====" << std::endl;
  add_integral(4, 5);       // OK, instantiates add_integral<int>
  add_integral('d', 'c');   // OK, instantiates add_integral<char>
  add_integral(true, true); // OK, instantiates add_integral<bool>
  // add_integral(4.0, 5.0);       // Error, substitution failure
  // add_integral("hello", "world"); // Error, substitution failure
}
} // namespace demo1

namespace demo2 {

/**
 * @brief Demonstration of using concepts to express template constraints.
 *
 */
template <typename IntegralType>
concept integral_constraint = std::is_integral<IntegralType>::value;
auto add_integral(const IntegralType v1, const IntegralType v2) {
  return v1 + v2;
}

void main() {
  add_integral(4, 5);       // OK, instantiates add_integral<int>
  add_integral('d', 'c');   // OK, instantiates add_integral<char>
  add_integral(true, true); // OK, instantiates add_integral<bool>
  // add_integral(4.0, 5.0);       // Error, substitution failure
  // add_integral("hello", "world"); // Error, substitution failure
}
} // namespace demo2

namespace demo3 {

/**
 * @brief Demonstration of using concepts to express template constraints,
 * and the use of the concept to constrain the auto deduced function parameters
 * as well as the auto deduced return type.
 *
 */
template <typename IntegralType>
concept integral_constraint = std::is_integral<IntegralType>::value;
integral_constraint auto add_integral(const integral_constraint auto v1,
                                      const integral_constraint auto v2) {
  return v1 + v2;
}

void main() {
  integral_constraint auto a =
      add_integral(4, 5); // OK, instantiates add_integral<int>
  integral_constraint auto b =
      add_integral('d', 'c'); // OK, instantiates add_integral<char>
  integral_constraint auto c =
      add_integral(true, true); // OK, instantiates add_integral<bool>
  // add_integral(4.0, 5.0);       // Error, substitution failure
  // add_integral("hello", "world"); // Error, substitution failure
}
} // namespace demo3

int main() {
  demo1::main();
  demo2::main();
  demo3::main();
  return 0;
}
