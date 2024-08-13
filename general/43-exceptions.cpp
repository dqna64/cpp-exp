#include <iostream>
#include <stdexcept>

void function2() {
	try {
		throw std::runtime_error("Something went wrong in function2");
	} catch (const std::exception& e) {
		std::cout << "Caught in function2: " << e.what() << std::endl;
		throw; // Rethrow the same exception
	}
}

void function1() {
	try {
		function2();
	} catch (const std::exception& e) {
		std::cout << "Caught in function1: " << e.what() << std::endl;
		throw;
	}
}

int main() {
	{
		try {
			function1();
		} catch (const std::exception& e) {
			std::cout << "Caught in main: " << e.what() << std::endl;
		}

		/**
		 * Output:
		 *
		 * Caught in function2: Something went wrong in function2
		 * Caught in function1: Something went wrong in function2
		 * Caught in main: Something went wrong in function2
		 *
		 */
	}
	return 0;
}
