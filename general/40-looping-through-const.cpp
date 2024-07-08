#include <iostream>
#include <vector>

namespace const_containers {
	void main() {
		{
			const std::vector<int> v1{1, 2, 3};

			// std::vector<int>& v2 = v1;
			// ERROR: qualifiers dropped in binding reference of type
			// std::vector<int> to const std::vector<int>

			std::vector<int> v3 = v1;
			// OKAY: copy semantics
			v3.push_back(4);
		}
	}
} // namespace const_containers

namespace looping_through_const_container {
	void main() {
		{
			// A modifiable container
			std::vector<std::string> v1{"1", "2", "3"};

			// A ref
			for (auto& item : v1) {
				std::cout << item << ", ";
				item = "done";
			}
		}

		{
			// A const container
			const std::vector<std::string> v1{"1", "2", "3"};

			// A ref
			for (auto& item : v1) {
				std::cout << item << ", ";
				// item = "done"; // ERROR: cannot assign to const lvalue
			}

			/**
			 * The auto type deduction implicitly treats item as
			 * const std::string& item since item is a reference to elements in
			 * a const container.
			 *
			 */
		}

		{
			// A modifiable container
			std::vector<std::string> v{"1", "2", "3"};

			// A const ref
			for (const auto& item : v) {
				std::cout << item << ", ";
				// item = "done"; // ERROR: cannot assign via const ref
			}

			/**
			 * const auto& item ensures elements are read-only in the loop, even
			 * though the container itself is modifiable.
			 *
			 */
		}

		{
			// A const container
			const std::vector<std::string> v{"1", "2", "3"};

			// A const ref
			for (const auto& item : v) {
				std::cout << item << ", ";
				// item = "done"; // ERROR: cannot assign via const ref
			}
		}
	}

} // namespace looping_through_const_container

int main() {
	looping_through_const_container::main();
}