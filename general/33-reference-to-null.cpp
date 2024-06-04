/**
 * @brief reference to pointer can be null?
 * no compile warning either, but we do get a segfault at runtime
 *
 * Technically this demo doesnt show that reference can be null. The reference
 * we made is to a pointer, and the pointer can be null sure. But the reference
 * itself is not null, it is referencing a valid memory location that is the
 * memory location of the pointer.
 */

#include <iostream>

int main() {
	int* x = nullptr;

	// reference to pointer which is null??
	int*& y = x;

	std::cout << *y << std::endl; // segfault xd

	int a = 5;
	y = &a;
	std::cout << *y << std::endl; // 5
}