/**
 * @brief Reference to dynamically allocated memroy
 * @version 0.1
 * @date 2024-06-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

int main() {
	int* heapMem = new int(42);
	int& tempRef = *heapMem;

	std::cout << "tempRef: " << tempRef << std::endl; // 42
	delete heapMem;
	std::cout << "tempRef: " << tempRef << std::endl;
	// Undefined behavior... clang outputed random bytes 22675536

	return 0;
}
