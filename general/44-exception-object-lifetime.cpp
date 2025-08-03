#include <iostream>
#include <stdexcept>

class MyException : public std::exception {
public:
	MyException() {
		std::cout << "MyException created" << std::endl;
	}

	~MyException() {
		std::cout << "MyException destroyed" << std::endl;
	}

	const char* what() const noexcept override {
		return "MyException occurred";
	}
};

void functionThatThrows() {
	MyException e;
	throw e; // This creates a copy of `e` that will be managed by the runtime
}

int main() {
	try {
		try {
			functionThatThrows();
		} catch (const MyException& ex) { // Catch by reference
			std::cout << "Caught: " << ex.what() << std::endl;
			throw;
			// At this point, the exception object managed by runtime is not yet
			// destroyed as it is rethrown and the outer catch block needs
			// a const reference to it.
		}
	} catch (const MyException& ex) {
		std::cout << "Caught again: " << ex.what() << std::endl;
		// At this point, the exception object will be destroyed
	}

	/**
	 * Output:
	 *
	 * MyException created       <= exception object created in scope functionThatThrows
	 * MyException destroyed     <= exception object destructed in scope functionThatThrows
	 * Caught: MyException occurred
	 * Caught again: MyException occurred
	 * MyException destroyed     <= exception object managed by runtime destructed
	 *
	 */
	return 0;
}
