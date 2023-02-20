/**
 * Type sizes vary depending on what system you are running you C/C++ code on
 * e.g. 32 bit, 64 bit systems
 */
#include <iostream>
#include <limits>

int main() {
	int int_max = std::numeric_limits<int>::max();
	int int_min = std::numeric_limits<int>::min();

	std::cout << int_max << std:: endl;
	std::cout << int_min << std::endl;
}

