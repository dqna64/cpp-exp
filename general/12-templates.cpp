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

namespace partial_specialisation_demo {

// General template
template <typename T> class MyClass {
public:
  void print() { std::cout << "General Template" << std::endl; }
};

// Partial specialization for string
template <> class MyClass<std::string> {
public:
  void print() { std::cout << "Specialization for string" << std::endl; }
};

// Partial specialization for pointer
template <typename K> class MyClass<K *> {
public:
  void print() { std::cout << "Specialization for pointer" << std::endl; }
};

int main() {
  std::cout << "==== Partial Specialisation Demo ====" << std::endl;
  MyClass<double> obj1; // Uses the general template
  obj1.print();         // Output: "General Template"

  MyClass<std::string> obj2; // Uses the partial specialization for string
  obj2.print();              // Output: "Specialization for string"

  MyClass<char *> obj3; // Uses the partial specialization for pointer
  obj3.print();         // Output: "Specialization for pointer"

  MyClass<std::array<int, 5>> obj4; // Uses the general template
  obj4.print();                     // Output: "General Template"

  return 0;
}
} // namespace partial_specialisation_demo
namespace type_traits_demo {

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
} // namespace type_traits_demo

} // namespace type_traits_demo

int main() {
  template_demo::main();
  partial_specialisation_demo::main();
  type_traits_demo::main();

  return 0;
}