#include <iostream>

int main() {
	{
		// =============== 4 basic types of memory issues ===============
		// === 1. Pointer to allocated heap memory (OK)
		int* ptr = new int(5);
		std::cout << "*ptr: " << *ptr << std::endl; // 5

		// === 2. Dangling pointer: addr still points to the memory location that was deallocated
		// (BAD)
		delete ptr;
		std::cout << "*ptr: " << *ptr << std::endl; // random bytes
		// attempt to derefence the pointer to deallocated heap memory
		// is undefined behavior. aka heap-use-after-free

		// === 2.1. Double free: deallocate memory twice (BAD)
		// delete ptr; // runtime error
		/* Runtime output:
		a.out(18850,0x2028ee080) malloc: *** error for object 0x600001a94050: pointer being freed was
		not allocated
		*/

		// === 3. Null pointer, heap memory deallocated (OK)
		ptr = nullptr;
		std::cout << "ptr: " << ptr << std::endl; // 0x0

		// === 4. Memory leak: allocated heap memory is not deallocated (BAD)
		ptr = new int(10);
		ptr = nullptr; // lost addr to allocated memory, can't deallocate

		// === 5. Dereference null pointer (BAD)
		// std::cout << "*ptr: " << *ptr << std::endl; // segmentation fault
	}
}