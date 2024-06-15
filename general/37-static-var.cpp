#include <iostream>

namespace demo1 {

	/**
	 * Static local variables, like global variables, are initialized to zero if not
	 * explicitly initialized. They are only initialized once, and retain their
	 * value for the life of the program (they are not re-initialized each time
	 * they come into scope)
	 *
	 */

	void increment() {
		static int staticLocalVar; // initialized to default value 0
		staticLocalVar++;
		std::cout << "staticLocalVar: " << staticLocalVar << std::endl;
	}
	void main() {
		increment(); // staticLocalVar: 1
		increment(); // staticLocalVar: 2
		increment(); // staticLocalVar: 3
	}
} // namespace demo1

namespace demo2 {
	/**
	 * Static member variables are shared among all objects of the class.
	 * Unlike static global and static local variables, static member variables
	 * are not default initialised to zero. They must be explicitly defined
	 * outside the class once.
	 *
	 */

	class MyClass {
	public:
		static int staticMemberVar;
		// Declaration of a static member variable inside the class.
		// Tells the compiler that the variable exists, but does not allocate memory for it.
		// The varaible must be defined outside the class because the memory is allocated only once.
	};

	int MyClass::staticMemberVar = 0;

	void main() {
		std::cout << "MyClass.staticMemberVar: " << ++MyClass::staticMemberVar << std::endl; // 1

		MyClass obj1, obj2, obj3;
		std::cout << "obj1.staticMemberVar: " << ++obj1.staticMemberVar << std::endl; // 2
		std::cout << "obj2.staticMemberVar: " << ++obj2.staticMemberVar << std::endl; // 3
		std::cout << "obj3.StaticMemberVar: " << ++obj3.staticMemberVar << std::endl; // 4
	}

} // namespace demo2

int main() {
	demo1::main();
	demo2::main();
}
