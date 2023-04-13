#include <iostream>

namespace demo1 {
/**
 * @brief Type deduction with for template functions or classes
 *
 * @tparam T
 * @tparam U
 * @param t
 * @param u
 * @return decltype(t + u)
 */
template <typename T, typename U> auto add(T t, U u) -> decltype(t + u) {
  return t + u;
}
int main() {
  std::cout << "=== demo1 ===" << std::endl;
  auto a = add(1, 2);
  std::cout << typeid(a).name() << std::endl; // int
  auto b = add(1.0, 2.0);
  std::cout << typeid(b).name() << std::endl; // double
  auto c = add(3, 4.0);
  std::cout << typeid(c).name() << std::endl; // double
  return 0;
}
} // namespace demo1

namespace demo2 {
int main() {
  std::cout << "=== demo2 ===" << std::endl;
  int a = 5;
  decltype(a) aa = 6;
  int &b = a;
  decltype((b)) bb = b;
  int &&c = std::move(5);
  decltype(c) cc = std::move(c);

  return 0;
}
} // namespace demo2

namespace demo3 {
/**
 * @brief Use decltype to deduce the return type of a function
 *
 * @tparam T
 * @param val
 * @return std::string
 */
template <typename T> auto time(T val) -> std::string {
  return std::to_string(val) + "s";
}
int main() {
  std::cout << "=== demo3 ===" << std::endl;
  decltype(time<>(5)) a = time(5);
  std::cout << a << std::endl;
  return 0;
}
} // namespace demo3

namespace demo4 {
template <typename T> auto get(T *begin, T *end, int i) -> decltype(*begin) {
  return *(begin + i);
}

void main() {
  std::cout << "=== demo4 ===" << std::endl;
  int a[] = {1, 2, 3, 4, 5};
  std::cout << get(a, a + 5, 2) << std::endl; // 3
}
} // namespace demo4

int main() {
  demo1::main();
  demo2::main();
  demo3::main();
  demo4::main();
  return 0;
}