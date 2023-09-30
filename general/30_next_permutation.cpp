#include <algorithm>
#include <iostream>
#include <string>
const int n = 6;

std::string arrayToString(int* arr);
int main() {
	int bits[n];

	std::fill(bits, bits + n / 2, 0);
	std::fill(bits + n / 2, bits + n, 1);

	do {
		std::cout << arrayToString(bits) << std::endl;
	} while (std::next_permutation(bits, bits + n));
}

std::string arrayToString(int* arr) {
	std::string str = "";
	for (int i = 0; i < n; i++) {
		str += std::to_string(arr[i]);
	}
	return str;
}
