#include <iostream>

int main() {
	int x = 10;

	int& ref = x;
	std::cout << "Size of reference: " << sizeof(ref) << " bytes" << std::endl;

	int* ptr = &x;
	std::cout << "Size of pointer: " << sizeof(ptr) << " bytes" << std::endl;

	return 0;
}
