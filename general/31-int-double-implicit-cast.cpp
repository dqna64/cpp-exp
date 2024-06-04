#include <iostream>

int main() {
	double x = 89.723;
	int y = x;
	std::cout << "x: " << x << std::endl; // 89.423
	std::cout << "y: " << y << std::endl; // 89
	std::cout << "x == y as doubles: " << (x == y) << std::endl; // 0
	std::cout << "x == y as ints: " << ((int)x == y) << std::endl; // 1

	auto z = static_cast<double>(y);
	std::cout << "z: " << z << std::endl; // 89
	std::cout << "z == y: " << (z == y) << std::endl; // 1
}