/**
 * This is interesting...
 * If you create an array, create a reference to an item in the array,
 * then reallocate the array, the reference becomes dangling.
 */

#include <iostream>
#include <vector>
int main() {
    auto v = std::vector<int>{};
    v.resize(3);
    v.emplace_back(50);
    v.emplace_back(60);
    v.emplace_back(70);

    auto& ir = v[0];
    std::cout << "ir: " << ir << "\n"; // 50

    v.reserve(10); // reallocate the backing array

    std::cout << "ir: " << ir << "\n"; // UB!!
}