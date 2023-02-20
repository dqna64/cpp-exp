#include <iostream>

using namespace std;

int main() {
	int a = 74;

	// top-level const: the pointer value is constant
	int * const p = &a;
	std::cout << "a befor " << *p << endl;

	*p = *p + 1;
	std::cout << "a after " << *p << endl;

;
	int b = 96;

	// bottom-level const: the pointee value is constant
	const int * q = &b;

	std::cout << "q befor " << q << endl;
	q = q + 1;
	std::cout << "q after " << q << endl;

}
