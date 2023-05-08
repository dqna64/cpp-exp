#include <array>
#include <iostream>

void print_arr_address(int *arr) {
  std::cout << "arr addr: " << arr << std::endl;
}

void print_array(int *arr, size_t size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void mutate_array(int arr[], size_t size) {
  if (size >= 1) {
    arr[0] += 1;
  }
}

void pass_to_fn_and_mutate() {
  std::array<int, 5> arr = {1, 2, 3, 4, 5};
  std::cout << "arr before mutate in fn" << std::endl;
  print_array(arr.data(), arr.size());
  mutate_array(arr.data(), arr.size());
  std::cout << "arr after mutate in fn" << std::endl;
  print_array(arr.data(), arr.size());
}

void array_front_back() {
  std::array<int, 5> a = {1, 2, 3, 4, 5};
  std::cout << "array front: " << a.front() << std::endl;
  std::cout << "array back: " << a.back() << std::endl;
}

int main(void) {
  // Declare an array with type and size.
  std::array<int, 5> a = {1, 2, 3, 4, 5};
  std::array<int, 5> a1;
  a1 = a;      // Copy a into a1 by assignment. Must have the EXACT same size.
  auto a2 = a; // Using auto, a2 has inferred type std::array<int, 5>
  auto a3(a);

  print_arr_address(a.data());

  pass_to_fn_and_mutate();

  array_front_back();

  return 0;
}