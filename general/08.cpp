#include <iostream>
#include <utility>

auto a(int &i) -> int & { return i; }

auto b(int &i) -> int && { return std::move(i); }

auto c(int &i) -> const int & { return i; }

auto d(int &i) -> const int && { return std::move(i); }

int main() {
  int x = 3;

  a(x) = 4;
  std::cout << "x: " << x << std::endl; // x is 4

  auto k = 8;
  auto m = b(k);
  m++;
  std::cout << "k: " << k << std::endl; // k is still 8
  std::cout << "m: " << m << std::endl; // m is 9
}
