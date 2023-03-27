#include <iostream>

// An anonymous namespace. It's members are injected into the enclosing scope.
namespace {
int x = 42;

// A namespace declared within the anonymous namespace.
namespace inner {
int x = 23;
}
} // namespace

int main() {
  std::cout << x << std::endl;        // prints 42
  std::cout << ::x << std::endl;      // Fully qualified member of the anonymous
                                      // namespace. prints 42
  std::cout << inner::x << std::endl; // prints 23
  std::cout << ::inner::x << std::endl; // Fully qualified. prints 23
  return 0;
}