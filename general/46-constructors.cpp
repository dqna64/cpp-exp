#include <cassert>
#include <iostream>
#include <sstream>

class MyClass {
public:
	int value;

	// Default Constructor
	MyClass()
	: value(0) {
		std::cout << "Default Constructor\n";
	}

	// Parameterized Constructor
	MyClass(int v)
	: value(v) {
		std::cout << "Parameterized Constructor\n";
	}

	// Copy Constructor
	MyClass(const MyClass& other)
	: value(other.value) {
		std::cout << "Copy Constructor\n";
	}

	// Move Constructor
	MyClass(MyClass&& other) noexcept
	: value(other.value) {
		other.value = 0; // Typically, the moved-from object is left in a valid state
		std::cout << "Move Constructor\n";
	}

	// Copy Assignment Operator
	MyClass& operator=(const MyClass& other) {
		if (this != &other) {
			value = other.value;
			std::cout << "Copy Assignment\n";
		}
		else {
			std::cout << "Copy Assignment did nothing\n";
		}
		return *this;
	}

	// Move Assignment Operator
	MyClass& operator=(MyClass&& other) noexcept {
		if (this != &other) {
			value = other.value;
			other.value = 0;
			std::cout << "Move Assignment\n";
		}
		else {
			std::cout << "Move Assignment did nothing\n";
		}
		return *this;
	}

	// Destructor
	~MyClass() {
		std::cout << "Destructor\n";
	}
};

int main() {
	// === Default constructor
	MyClass obj1;

	// === Parameterised constructor
	MyClass obj2(2);
	MyClass obj3{3};
	MyClass obj4 = 4;
	MyClass obj5 = {5};

	// === Copy constructor
	MyClass obj6(obj2);
	MyClass obj7{obj3};
	MyClass obj8 = obj4;
	MyClass obj9 = {obj5};
	const MyClass constObj1 = obj6; // construct copy const from non-const
	const MyClass constObj2 = constObj1; // construct copy const from const
	MyClass constObj3 = constObj1; // construct copy non-const from const

	// === Move constructor
	MyClass obj10(std::move(obj6));
	MyClass obj11{std::move(obj7)};
	MyClass obj12 = std::move(obj8);
	MyClass obj13 = {std::move(obj9)};

	// === Copy assignment
	obj6 = obj10;
	obj7 = obj7; // did nothing
	obj8 = constObj1; // assign copy to non-const from const
	// constObj2 = obj11; // cannot assign copy to const

	// Copy assignment from temporary object, compiler turns it into
	// a move assignment.
	// Parameterized constructor + Move assignment
	obj10 = 438;

	// === Move assignment
	obj6 = std::move(obj10);
	obj11 = std::move(obj11); // did nothing

	// Move assignment from temporary object
	// Parameterized constructor + Move assignment
	obj8 = std::move(32);
}
