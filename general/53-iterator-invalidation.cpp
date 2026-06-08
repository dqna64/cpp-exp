#include <iostream>
#include <vector>

int main() {
    {
        auto v = std::vector<int>{1, 2, 3};
        auto it = v.begin();

        std::cout << v.capacity() << "\n"; // suppose this is 3

        v.push_back(4); // if capacity was 3, inserting new item here forces reallocation of the backing array
        // The iterator is invalid now
        std::cout << "*it: " << *it << "\n"; // UB
        //                      ^^
        // ==33267==ERROR: AddressSanitizer: heap-use-after-free on address 0x000106f006f0 at pc 0x0001042e1978 bp
        // 0x00016bb22df0 sp 0x00016bb22de8
    }

    {
        auto v = std::vector<int>{1, 2, 3};
        // Reserve enough space for insertions
        // Guarantees no reallocation until size exceeds 5
        // NOTE: this reserve operation itself will cause reallocation
        v.reserve(5);

        auto it = v.begin();
        std::cout << v.capacity() << "\n"; // at least 5

        v.push_back(4); // no reallocation
        // The iterator is not invalidated
        std::cout << "*it: " << *it << "\n"; // 1
    }
}