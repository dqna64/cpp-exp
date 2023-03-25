#include <iostream>
#include <vector>

int main(void) {

  std::vector<std::vector<int>> a;
  std::vector<int> a1 = {1, 2, 3};
  std::vector<int> a2 = {4, 5, 6};
  std::vector<int> a3 = {7, 8, 9};
  a.push_back(a1);
  a.push_back(a2);
  a.push_back(a3);

  auto b = a;
  a[0][0] = 9;

  std::cout << "a[0][0]: " << a[0][0] << std::endl;
  std::cout << "b[0][0]: " << b[0][0] << std::endl;

  return 0;
}
