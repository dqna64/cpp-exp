#include <execution>
#include <iostream>
#include <numeric>
#include <vector>

auto vec = std::vector<int>{1, 2, 3, 4, 5};

int sum_by_reduce(const std::vector<int>& vec) {
	int total = std::reduce(vec.begin(), vec.end(), 0, [](int acc, int val) { return acc + val; });
	std::cout << "Total: " << total << std::endl;
	return total;
}
int sum_by_accumulate(const std::vector<int>& vec) {
	int total = std::accumulate(vec.begin(), vec.end(), 0);
	std::cout << "Total: " << total << std::endl;
	return total;
}

/**
 * @brief map-reduce using transform_reduce
 *
 * Takes in vector of integers and returns the sum of half of even numbers
 * and double of odd numbers
 */
int map_reduce(const std::vector<int>& vec) {
	int total = std::transform_reduce(
	   vec.begin(),
	   vec.end(),
	   0,
	   [](int acc, int val) { return acc + val; },
	   [](int val) { return val % 2 == 0 ? val / 2 : val * 2; });
	std::cout << "Total: " << total << std::endl;
	return total;
}

/**
 * @brief Implement python zip using transform with two input iterators
 *
 */
auto zip(const std::vector<int>& v1, const std::vector<int>& v2) -> std::vector<std::pair<int, int>> {
	auto res = std::vector<std::pair<int, int>>(std::min(v1.size(), v2.size()));
	std::transform(v1.begin(), v1.end(), v2.begin(), res.begin(), [](int a, int b) {
		return std::make_pair(a, b);
	});
	std::cout << "Zipped: " << std::endl;
	for (const auto& [a, b] : res) {
		std::cout << a << " " << b << std::endl;
	}
	return res;
}

int main() {
	sum_by_reduce(vec);
	sum_by_accumulate(vec);
	map_reduce(vec);

	auto zip1 = std::vector<int>{1, 3, 5, 7, 9};
	auto zip2 = std::vector<int>{2, 4, 6, 8};
	zip(zip1, zip2);
}
