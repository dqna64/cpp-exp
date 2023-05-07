#include <cstring>
#include <iostream>
#include <vector>
namespace a {
class String {
public:
  String(const char *s) {
    size_ = std::strlen(s);
    data_ = new char[size_ + 1]; // Allocate memory
    std::strcpy(data_, s);       // Copy the contents
  }

  // Copy constructor
  String(const String &other) {
    size_ = other.size_;
    data_ = new char[size_ + 1];     // Allocate new memory block
    std::strcpy(data_, other.data_); // Copy the contents of the other.data_
                                     // memory block into the new memory block,
                                     // preserving the other.data_ memory block
  }

  // Move constructor
  String(String &&other) noexcept {
    size_ = other.size_; // copy other.size_ since it's a simple scalar value
    data_ =
        other.data_; // Transfer ownership; new data_ points to the memory block
    // that was originally allocated for other.data_

    other.size_ = 0;
    other.data_ = nullptr; // Leave the source object in a valid state
  }

  // Destructor
  ~String() { delete[] data_; }

private:
  std::size_t size_;
  char *data_;
};
} // namespace a

namespace b {
void main() {
  std::vector<int> p = std::vector<int>{1, 2, 3};
  std::vector<int> r = std::move(p);
  std::vector<int> s = std::move(p);

  // p should be empty since it has been moved to r
  std::cout << "p: ";
  for (auto &i : p) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // r should have the original contents of p
  std::cout << "r: ";
  for (auto &i : r) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // s should be empty since p had already been moved to r
  std::cout << "s: ";
  for (auto &i : s) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}
} // namespace b

int main() { b::main(); }