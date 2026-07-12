#include <cstddef>
#include <iostream>

/**
 * This program demonstrates how destructors are implicitly marked as noexcept.
 * This is to satify rules of RAII, i.e. to allow safe stack unwinding.
 */

struct Container {
    int* items_;

    Container(size_t size)
    : items_{new int[size]} {
        std::cout << "Container()\n";
    }

    ~Container() {
        std::cout << "~Container()\n";

        throw;
        // ^^ERROR: Destructor is implicitly noexcept
        // Need to handle this exception.

        std::cout << "deleting items_\n";
        delete[] items_;
    }
};

int main() {
    {
        auto a = Container{5};
    }
}