#include <iostream>
#include <memory>
#include <stdexcept>

class Widget {
	int id;

public:
	Widget(int i)
	: id(i) {
		std::cout << "Widget " << id << " created\n";
	}

	~Widget() {
		std::cout << "Widget " << id << " destroyed\n";
	}

	void show() {
		std::cout << "Widget " << id << "\n";
	}
};

// Function that takes two unique_ptrs - shows exception safety issue
void process(std::unique_ptr<Widget> a, std::unique_ptr<Widget> b) {
	a->show();
	b->show();
}

int main() {
	std::cout << "=== REASON 1: EXCEPTION SAFETY ===\n";

	// PROBLEM: If second 'new' throws, first allocation leaks!
	// process(
	//     std::unique_ptr<Widget>(new Widget(1)),  // This succeeds
	//     std::unique_ptr<Widget>(new Widget(2))   // If this throws -> LEAK!
	// );

	// SOLUTION: make_unique is exception-safe
	process(std::make_unique<Widget>(1), // Safe
	        std::make_unique<Widget>(2) // Safe - no leak possible
	);

	std::cout << "\n=== REASON 2: NO RAW NEW/DELETE ===\n";

	// OLD WAY: Manual memory management
	Widget* raw = new Widget(10);
	raw->show();
	delete raw; // Must remember this!

	// NEW WAY: Automatic cleanup
	{
		auto smart = std::make_unique<Widget>(20);
		smart->show();
		// Automatically deleted when 'smart' goes out of scope
	}

	std::cout << "\n=== REASON 3: PREVENTS OWNERSHIP ERRORS ===\n";

	// PROBLEM: Raw pointers can lead to ownership confusion
	Widget* raw_ptr = new Widget(50);

	// BAD: Multiple ownership (double delete!)
	// std::unique_ptr<Widget> ptr1(raw_ptr);
	// std::unique_ptr<Widget> ptr2(raw_ptr);  // DISASTER!

	// BAD: Forgot to take ownership (memory leak!)
	// Widget* forgotten = new Widget(60);
	// // ... code continues without wrapping in unique_ptr

	// GOOD: make_unique creates AND owns in one step
	auto safe1 = std::make_unique<Widget>(70);
	auto safe2 = std::make_unique<Widget>(80);
	// No way to accidentally share or forget ownership!

	delete raw_ptr; // Manual cleanup for demo

	std::cout << "\n=== REASON 4: PERFECT FORWARDING ===\n";

	// make_unique forwards all arguments perfectly to constructor
	class MultiArg {
		int a, b;

	public:
		MultiArg(int x, int y)
		: a(x)
		, b(y) {
			std::cout << "MultiArg(" << a << ", " << b << ") created\n";
		}
		~MultiArg() {
			std::cout << "MultiArg destroyed\n";
		}
	};

	// All constructor arguments forwarded correctly
	auto multi = std::make_unique<MultiArg>(100, 200);

	std::cout << "\nAll objects automatically cleaned up at end!\n";
	return 0;
}

/*
SUMMARY - Why use make_unique instead of new:

1. EXCEPTION SAFETY: Prevents memory leaks when exceptions occur
2. NO RAW NEW/DELETE: Automatic cleanup, no manual delete needed
3. PREVENTS OWNERSHIP ERRORS: Can't accidentally own resource multiple times or forget to own it
4. PERFECT FORWARDING: Constructor arguments passed correctly
5. MODERN C++: Consistent with make_shared and other utilities

RULE: Always use make_unique instead of new for unique_ptr!
*/