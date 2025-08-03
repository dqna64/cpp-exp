/**
 * $ g++ -std=c++20  heap-vector.cpp && ./a.out
 */

#include <iostream>
#include <vector>

// The newly created heap resource outlives the scope in which it
// was created.
auto create_heap_vec() -> std::vector<int>* {
	// Use new keyword to create a std::vector<int> on the heap
	// and return a pointer to that resource.
	std::vector<int>* heap_vec_ptr = new std::vector<int>{1, 2, 3};
	return heap_vec_ptr;
}

int main() {
	std::vector<int>* heap_vec = create_heap_vec();

	std::cout << "Addr of heap vector: " << heap_vec << std::endl;
	std::cout << "First element of heap vector: " << (*heap_vec).at(0) << std::endl;

	delete heap_vec;
}