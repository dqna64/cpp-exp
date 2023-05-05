#include <array>
#include <iostream>
#include <vector>

namespace template_demo {
template <typename T> std::vector<T> sort_trio(T a, T b, T c) {
  auto trio = std::vector<T>{a, b, c};
  if (trio[0] > trio[1]) {
    std::swap(trio[0], trio[1]);
  };
  if (trio[1] > trio[2]) {
    std::swap(trio[1], trio[2]);
  };
  if (trio[0] > trio[1]) {
    std::swap(trio[0], trio[1]);
  };
  return trio;
}

int main() {
  std::cout << "==== Template Demo ====" << std::endl;
  std::cout << "==== Sort ints ====" << std::endl;
  auto sorted_int_trio = sort_trio(2, 3, 1);
  for (auto i : sorted_int_trio) {
    std::cout << i << std::endl;
  }

  std::cout << "==== Sort doubles ====" << std::endl;
  auto sorted_double_trio = sort_trio(2.0, 3.0, 1.0);
  for (auto i : sorted_double_trio) {
    std::cout << i << std::endl;
  }

  std::cout << "==== Sort strings ====" << std::endl;
  auto sorted_string_trio = sort_trio(
      std::string("tallis"), std::string("tallow"), std::string("tallage"));
  for (auto i : sorted_string_trio) {
    std::cout << i << std::endl;
  }

  std::cout << "==== Sort chars ====" << std::endl;
  auto sorted_char_trio = sort_trio('b', 'c', 'a');
  for (auto i : sorted_char_trio) {
    std::cout << i << std::endl;
  }

  return 0;
}
} // namespace template_demo

namespace specialisation_demo {

// General template
template <typename T> class MyClass {
public:
  void print() { std::cout << "General Template" << std::endl; }
};

// Explicit specialization for string
template <> class MyClass<std::string> {
public:
  void print() {
    std::cout << "Explicit Specialization for string" << std::endl;
  }
};

// Partial specialization for pointer
template <typename K> class MyClass<K *> {
public:
  void print() {
    std::cout << "Partial Specialization for pointer" << std::endl;
  }
};

int main() {
  std::cout << "==== Specialisation Demo ====" << std::endl;
  MyClass<double> obj1; // Uses the general template
  obj1.print();         // Output: "General Template"

  MyClass<std::string> obj2; // Uses the explicit specialization for string
  obj2.print();              // Output: "Specialization for string"

  MyClass<char *> obj3; // Uses the partial specialization for pointer
  obj3.print();         // Output: "Specialization for pointer"

  MyClass<std::array<int, 5>> obj4; // Uses the general template
  obj4.print();                     // Output: "General Template"

  return 0;
}
} // namespace specialisation_demo
namespace type_traits_demo {

/**
 * Demonstration of using type trait to change logic based on type.
 */

template <typename T> struct is_void {
  static const bool value = false;
};
template <> struct is_void<void> {
  static const bool value = true;
};

template <typename T> class MyClass {
public:
  MyClass() {
    if (is_void<T>::value) {
      std::cout << "Type is void" << std::endl;
    } else {
      std::cout << "Type is not void" << std::endl;
    }
  };
};

int main() {
  std::cout << "==== Type Traits Demo ====" << std::endl;
  MyClass<int> obj1;  // Type is not void, prints "Type is not void"
  MyClass<void> obj2; // Type is void, prints "Type is void"
  return 0;
}

} // namespace type_traits_demo

namespace type_traits_demo_2 {
#include <iostream>
#include <type_traits>

// Type trait to determine if a type is a pointer
template <typename T> struct IsPointer {
  static const bool value = false;
};

template <typename T> struct IsPointer<T *> {
  static const bool value = true;
};

// Test function
template <typename T> void printTypeTrait() {
  if (IsPointer<T>::value) {
    std::cout << typeid(T).name() << " is a pointer." << std::endl;
  } else {
    std::cout << typeid(T).name() << " is not a pointer." << std::endl;
  }
}

int main() {
  std::cout << "==== Type Traits Demo 2 ====" << std::endl;
  printTypeTrait<int>();     // Output: "int is not a pointer."
  printTypeTrait<float *>(); // Output: "float* is a pointer."
  printTypeTrait<char>();    // Output: "char is not a pointer."

  return 0;
}

} // namespace type_traits_demo_2

namespace type_traits_demo_3 {
/**
 * Demo type trait to determine if a type is a number
 *
 */
template <typename T> void print_is_number(T x) {
  if (std::is_integral<T>::value) {
    std::cout << "Type is integral" << std::endl;
  } else {
    std::cout << "Type is not integral" << std::endl;
  }
}

int main() {
  std::cout << "==== Type Traits Demo 3 ====" << std::endl;
  print_is_number(1);                   // Type is integral
  print_is_number(1.0);                 // Type is not integral
  print_is_number('c');                 // Type is integral
  print_is_number(std::string("word")); // Type is not integral

  return 0;
}
} // namespace type_traits_demo_3

int main() {
  template_demo::main();
  specialisation_demo::main();
  type_traits_demo::main();
  type_traits_demo_2::main();
  type_traits_demo_3::main();

  return 0;
}