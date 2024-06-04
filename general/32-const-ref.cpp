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
		int y = 6;

		int const& a = x;

		// a++;
		// Compile error: expression must be a modifiable lvalue
		// a is a constant reference to an integer variable, so we cannot modify
		// the value of x through a
	}
} // namespace part2

int main() {
	part1::main();
	part2::main();
}