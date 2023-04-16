#include <string>
#include <type_traits>

namespace sfinae_function_templates {
/**
 * @brief Substitution failure is not an error
 *
 */

// When "B" is true, maybe::type exists and is T.
// When "B" is false... there is no type!
template <bool B, typename T> struct maybe {
  using type = T;
};
template <typename T> struct maybe<false, T> {};
template <bool B, typename T> using maybe_t = typename maybe<B, T>::type;
template <typename T>
// For non-integral types, there is no return type.
// That is ill-formed, so this overload is silently discarded
maybe_t<std::is_integral<T>::value, T> secret_algorithm(T i) {
  return i * 2;
}
template <typename T>
// For non-floating point types, there is no return type.
// That is ill-formed, so this overload is silently discarded
maybe_t<std::is_floating_point<T>::value, T> secret_algorithm(T fp) {
  return fp * T{3.14};
}
int main() {
  int secret_int = secret_algorithm(6771);
  float secret_float = secret_algorithm(3.14f);
  double secret_double = secret_algorithm(3.14);
  // std::string secret_string = secret_algorithm("hello"); // Substitution
  // failure at compile time
}
// Here, we don't have two overloads of "secret_algorithm";
// For "int" vs. "float", we explicitly remove the other
// overload from the resolution set using SFINAE!
} // namespace sfinae_function_templates

int main() {
  sfinae_function_templates::main();
  return 0;
}