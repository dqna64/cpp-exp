/**
 * @brief (const int&) vs (int const&), they are essentially the same
 *
 */

namespace part1 {
	/**
	 * @brief reference to constant variable
	 *
	 */
	void main() {
		int x = 5;

		const int& a = x;

		// a++;
		// Compile error: expression must be a modifiable lvalue
		// a is a reference to an integer that has been made constant
		// so we cannot modify the value of x through a
	}
} // namespace part1

namespace part2 {
	/**
	 * @brief const reference to modifiable variable
	 *
	 */
	void main() {
		int x = 5;

		int const& a = x;

		// a++;
		// Compile error: expression must be a modifiable lvalue
		// a is a constant reference to an integer variable, so we cannot modify
		// the value of x through a
	}
} // namespace part2

namespace part3 {
	void main() {
		const int x = 5;

		/**
		 * Since (const T&) and (T const&) are essentially the same,
		 * we can use either syntax to define a reference to a const variable.
		 * Both a and b work.
		 */
		const int& a = x;
		int const& b = x;

		// Note we cannot bind a non-const reference to a const variable
		// int& c = x;
		// Compile error: qualifiers dropped in binding reference of type
		// 'int&' to 'const int'
	}
} // namespace part3

namespace part4 {
	void main() {
		int x = 5;

		// This is invalid syntax. Even if it was, it would be pointless because
		// references are constant by default
		// ie you cannot change what a reference refers to after it has been
		// initialized.
		int& const b = x;
		// Compile error: 'const' qualifier may not be applied to a reference

		b++;
		int y = 10;
		b = y;
	}
} // namespace part4

int main() {
	part1::main();
	part2::main();
	part3::main();
	part4::main();
}