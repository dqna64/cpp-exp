#include <iostream>

/**
 * You can do anything in a custom destructor, including:
 * - deleting outside memory (can lead to dangling pointers)
 * - not destructing the memory created inside the object (can lead to memory leaks)
 */

class MyClass {
public:
	int* outsideMemPtr;
	int* insideMemPtr;
	MyClass(int* outsideMemPtr) {
		std::cout << "MyClass(...) called" << std::endl;
		this->outsideMemPtr = outsideMemPtr;
		this->insideMemPtr = new int(8);
	}

	int* getInsideMemoryPtr() {
		return insideMemPtr;
	}

	~MyClass() {
		std::cout << "~MyClass() called" << std::endl;

		// Forget to delete insideMemPtr

		delete outsideMemPtr;
	}
};

int main() {
	int* outsideMemPtr = new int(5);
	int* insideMemPtr;
	std::cout << "*outsideMemPtr: " << *outsideMemPtr << std::endl; // 5
	if (true) {
		MyClass obj(outsideMemPtr);
		insideMemPtr = obj.getInsideMemoryPtr();
	}
	std::cout << "*outsideMemPtr: " << *outsideMemPtr << std::endl;
	// random bytes because outsideMemPtr was deleted by the classes destructor

	std::cout << "*insideMemPtr: " << *insideMemPtr << std::endl;
	// 8 because insideMemPtr was not deleted by the classes destructor
	// memory leak

	return 0;
}