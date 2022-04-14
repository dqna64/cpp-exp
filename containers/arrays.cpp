#include <iostream>
#include <array>

void print_arr_address(int *arr, size_t size) {
    std::cout << "arr: " << arr << std::endl;
}

int main(void) {
    // Declare an array with type and size.
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    std::array<int, 5> a1;
    a1 = a; // Copy a into a1 by assignment. Must have the EXACT same size.
    auto a2 = a; // Using auto, a2 has inferred type std::array<int, 5>
    auto a3(a);

    print_arr_address(a.data(), a.size());
    
    return 0;
}