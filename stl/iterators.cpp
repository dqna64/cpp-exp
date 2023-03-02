#include <iostream>
#include <vector>

int main() {

  auto items = std::vector<int>(); // empty vector

  std::cout << (items.begin() == items.end() ? "true" : "false") << std::endl;
}