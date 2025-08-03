#include <iostream>

class Sequence {
public:
	Sequence(int size) {
		// This is how to allocate an object on heap in C++
		size_ = new long long{size};
		// This is how to allocate an array on heap in C++
		data_ = new int[size];
		for (int i = 0; i < size; i++) {
			data_[i] = i;
		}
		std::cout << "Constructed Sequence object with size " << *size_ << std::endl;
	}

	~Sequence() {
		delete size_;
		delete[] data_;
		std::cout << "Destructed Sequence object" << std::endl;
	}

private:
	long long* size_;
	int* data_;
};

int main() {
	Sequence s{4};
}