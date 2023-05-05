#include <iostream>
#include <tuple>
#include <typeindex>
#include <typeinfo>
#include <vector>

// namespace demo1 {
// template <typename Tuple> struct make_typeinfo_from_tuple;

// template <typename... Args>
// struct make_typeinfo_from_tuple<std::tuple<Args...>> {
//   static constexpr auto size = sizeof...(Args);
//   static constexpr std::array<std::type_index, size> value = {
//       std::type_index(typeid(Args))...};
// };

// // Example usage:
// int main() {
//   auto types = make_typeinfo_from_tuple<std::tuple<int, double>>::value;
//   // `types` now contains the type_info objects for `int` and `double`.
//   return 0;
// }
// } // namespace demo1

namespace demo2 {

template <typename Tuple, std::size_t... Is>
constexpr auto make_typeinfo_vector_impl(std::index_sequence<Is...>) {
  return std::vector<std::type_index>{
      std::type_index(typeid(std::tuple_element_t<Is, Tuple>))...};
}

template <typename Tuple> constexpr auto make_typeinfo_vector() {
  return make_typeinfo_vector_impl<Tuple>(
      std::make_index_sequence<std::tuple_size<Tuple>::value>{});
}

void main() {
  auto types = make_typeinfo_vector<std::tuple<int, int *, int &, int &&>>();
  for (auto t : types) {
    std::cout << t.name() << std::endl;
  }
  // `types` now contains the type_info objects for `int` and `double`.
}

} // namespace demo2

int main() { demo2::main(); }