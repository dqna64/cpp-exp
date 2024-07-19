#include <algorithm>
#include <iostream>
#include <iterator>

// Forward iterator class template
template<typename T>
class Iterator {
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using reference = T&;
	using pointer = T*;
	using difference_type = std::ptrdiff_t;

	Iterator(pointer ptr = nullptr)
	: m_ptr(ptr) {}

	reference operator*() const {
		return *m_ptr;
	}

	Iterator& operator++() {
		++m_ptr;
		return *this;
	}

	Iterator operator++(int) {
		Iterator copy = *this;
		++(*this);
		return copy;
	}

	Iterator& operator--() {
		--m_ptr;
		return *this;
	}

	Iterator operator--(int) {
		Iterator copy = *this;
		--(*this);
		return copy;
	}

	Iterator operator+(difference_type n) const {
		return Iterator(m_ptr + n);
	}

	Iterator operator-(difference_type n) const {
		return Iterator(m_ptr - n);
	}

	difference_type operator-(const Iterator& other) const {
		return m_ptr - other.m_ptr;
	}

	bool operator<(const Iterator& other) const {
		return m_ptr < other.m_ptr;
	}

	bool operator>(const Iterator& other) const {
		return m_ptr > other.m_ptr;
	}

	bool operator<=(const Iterator& other) const {
		return m_ptr <= other.m_ptr;
	}

	bool operator>=(const Iterator& other) const {
		return m_ptr >= other.m_ptr;
	}

	pointer operator->() const {
		return m_ptr;
	}

	friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
		return lhs.m_ptr == rhs.m_ptr;
	}

	friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
		return !(lhs == rhs);
	}

private:
	pointer m_ptr;
};

// Reverse iterator class template
template<typename T>
class ReverseIterator {
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	using reference = T&;
	using pointer = T*;
	using difference_type = std::ptrdiff_t;

	ReverseIterator(pointer ptr = nullptr)
	: m_ptr(ptr) {}

	reference operator*() const {
		pointer temp = m_ptr;
		return *--temp;
	}

	ReverseIterator& operator++() {
		--m_ptr;
		return *this;
	}

	ReverseIterator operator++(int) {
		ReverseIterator copy = *this;
		--(*this);
		return copy;
	}

	ReverseIterator& operator--() {
		++m_ptr;
		return *this;
	}

	ReverseIterator operator--(int) {
		ReverseIterator copy = *this;
		++(*this);
		return copy;
	}

	ReverseIterator operator+(difference_type n) const {
		return ReverseIterator(m_ptr - n);
	}

	ReverseIterator operator-(difference_type n) const {
		return ReverseIterator(m_ptr + n);
	}

	difference_type operator-(const ReverseIterator& other) const {
		return other.m_ptr - m_ptr;
	}

	bool operator<(const ReverseIterator& other) const {
		return m_ptr > other.m_ptr;
	}

	bool operator>(const ReverseIterator& other) const {
		return m_ptr < other.m_ptr;
	}

	bool operator<=(const ReverseIterator& other) const {
		return m_ptr >= other.m_ptr;
	}

	bool operator>=(const ReverseIterator& other) const {
		return m_ptr <= other.m_ptr;
	}

	pointer operator->() const {
		pointer temp = m_ptr;
		return --temp;
	}

	friend bool operator==(const ReverseIterator& lhs, const ReverseIterator& rhs) {
		return lhs.m_ptr == rhs.m_ptr;
	}

	friend bool operator!=(const ReverseIterator& lhs, const ReverseIterator& rhs) {
		return !(lhs == rhs);
	}

private:
	pointer m_ptr;
};

// Custom container class
template<typename T>
class MyContainer {
public:
	using iterator = Iterator<T>;
	using const_iterator = Iterator<const T>;
	using reverse_iterator = ReverseIterator<T>;
	using const_reverse_iterator = ReverseIterator<const T>;
	using value_type = T;

	MyContainer(size_t size)
	: m_size(size)
	, m_data(new T[size]) {}

	~MyContainer() {
		delete[] m_data;
	}

	T& operator[](size_t index) {
		return m_data[index];
	}

	const T& operator[](size_t index) const {
		return m_data[index];
	}

	iterator begin() {
		return iterator(m_data);
	}

	iterator end() {
		return iterator(m_data + m_size);
	}

	const_iterator begin() const {
		return const_iterator(m_data);
	}

	const_iterator end() const {
		return const_iterator(m_data + m_size);
	}

	reverse_iterator rbegin() {
		return reverse_iterator(m_data + m_size);
	}

	reverse_iterator rend() {
		return reverse_iterator(m_data);
	}

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(m_data + m_size);
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(m_data);
	}

private:
	size_t m_size;
	T* m_data;
};

// Function to print elements of a container
template<typename Container>
void printContainer(const Container& container) {
	for (auto it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Function to print elements of a container in reverse
template<typename Container>
void printContainerReverse(const Container& container) {
	for (auto it = container.rbegin(); it != container.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// Function to find an element in a container
template<typename Container, typename T>
typename Container::iterator findElement(Container& container, const T& value) {
	for (auto it = container.begin(); it != container.end(); ++it) {
		if (*it == value) {
			return it;
		}
	}
	return container.end();
}

// Function to reverse elements in a container
template<typename Container>
void reverseContainer(Container& container) {
	std::reverse(container.begin(), container.end());
}

int main() {
	// Create a custom container with 5 elements
	MyContainer<int> myContainer(5);

	// Initialize the container
	myContainer[0] = 1;
	myContainer[1] = 2;
	myContainer[2] = 3;
	myContainer[3] = 4;
	myContainer[4] = 5;

	// Print the original container
	std::cout << "Original container: ";
	printContainer(myContainer);

	// Find an element in the container
	int valueToFind = 3;
	auto foundIt = findElement(myContainer, valueToFind);
	if (foundIt != myContainer.end()) {
		std::cout << "Found value " << valueToFind
		          << " at position: " << (foundIt - myContainer.begin()) << std::endl;
	}
	else {
		std::cout << "Value " << valueToFind << " not found" << std::endl;
	}

	// Reverse the container
	reverseContainer(myContainer);

	// Print the reversed container
	std::cout << "Reversed container: ";
	printContainer(myContainer);

	// Print the container using reverse iterator
	std::cout << "Container printed in reverse: ";
	printContainerReverse(myContainer);

	// Sort the container
	std::sort(myContainer.begin(), myContainer.end());

	// Print the sorted container
	std::cout << "Sorted container: ";
	printContainer(myContainer);

	return 0;
}
