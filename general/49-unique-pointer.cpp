#include <iostream>
#include <memory>

template<typename T>
auto print(T a) {
	std::cout << a << std::endl;
}

int main() {
	{
		auto up1 = std::unique_ptr<int>{new int{52}};
		// auto up2 = up1; // no copy constructor
		std::unique_ptr<int> up3;
		// up3 = up2; // no copy assignment

		up3.reset(up1.release()); // OK
		print(up3.get()); // 0x600002604050
		// print(*up1); // seqfault

		auto up4 = std::move(up3); // OK
		print(up4.get()); // 0x600002604050
		print(*up4); // 52
		// print(*up3); // segfault
	}
}