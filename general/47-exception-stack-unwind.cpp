#include <iostream>
#include <vector>

template<std::size_t N>
class MyClass {
public:
	// Takes in only string literals; a reference to a const char
	// array of size N
	MyClass(const char (&name)[N], int a) {
		name_ = new char[N];
		std::strcpy(name_, name);
		std::cout << "Constructor for MyClass " << name_ << std::endl;
	}

	~MyClass() noexcept {
		std::cout << "Destructor for MyClass" << name_ << std::endl;
		delete[] name_;
	}

private:
	char* name_;
};

void fn() {
	auto stackObj = MyClass{"Stack obj", 1};
	auto heapObjPtr = new MyClass{"Heap obj", 2};
	auto managedHeapObjPtr = std::unique_ptr<MyClass<17>>(new MyClass{"Managed heap obj", 3});

	throw std::runtime_error("Error occurred");
	// stackObj will be destructed
	// heapObj will NOT be destructed
	// (only the pointer heapObjPtr will be destructed)
	// managedHeapObj will be destructed via the destructor of the
	// unique_ptr
};

int main() {
	try {
		fn();
	} catch (std::runtime_error const& e) {
		std::cout << "Caught error in fn(): " << e.what() << std::endl;
	}
}

/*
Output:

Constructor for MyClass Stack obj
Constructor for MyClass Heap obj
Constructor for MyClass Managed heap obj
Destructor for MyClassManaged heap obj
Destructor for MyClassStack obj
Caught error in fn(): Error occurred
 */