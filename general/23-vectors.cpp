#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

void print_vector(std::string name, std::vector<int> v) {
  std::cout << name << ": ";
  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}

bool isPerfectSquare(int x) {
  if (x >= 0) {
    return (ceil((double)sqrt(x)) == floor((double)sqrt(x)));
  } else {
    return false;
  }
}

void vector_copy() {
  auto nums = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto perfectSquares = std::vector<int>(4); // Allocate space for 4 integers

  std::copy_if(nums.begin(), nums.end(), perfectSquares.begin(),
               isPerfectSquare);

  print_vector("List of nums", nums);
  print_vector("Perfect squares", perfectSquares);
}

int main(void) {

  std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
  std::vector<int> v2;

  v2 = v1;     // Copy v1 into v2 by assignment.
  auto v3(v1); // Or make copy by passing into constructor.

  std::cout << "front of v1: " << v1.front() << std::endl;
  std::cout << "back of v1: " << v1.back() << std::endl;
  std::cout << "size of v1: " << v1.size() << std::endl;
  std::cout << "item at index 2 of v1: " << v1[2] << std::endl;
  std::cout << "item at index 2 of v2: " << v2.at(2) << std::endl;
  std::cout << "item at index 2 of v3: " << v1.data()[2] << std::endl;

  v2.insert(v2.begin(), -124);
  v2.insert(v2.end(), -352);
  print_vector("v2", v2);

  v1.erase(v1.begin()); // remove first element
  v1.pop_back();        // same as v1.erase(v1.end() - 1);
  print_vector("v1", v1);

  v1.clear();
  // All elements of v1 are now gone and size of v1 is 0.
  std::cout << "size of v1: " << v1.size() << std::endl;
  // But capacity remains at initial.
  std::cout << "capacity of v1: " << v1.capacity() << std::endl;

  // vector is a container class, so container operations work on it.
  std::sort(v2.begin(), v2.end());
  print_vector("v2", v2);

  return 0;
}
