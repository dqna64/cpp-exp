#include <iostream>
#include <vector>

/**
 * Demonstrate member templates
 *
 * @tparam T
 */

template <typename T> class Stack {
public:
  // Default constructor
  Stack() {}
  template <typename T2>
  Stack(Stack<T2> &); // Copy constructor templated on some type T2

  // Destructor
  ~Stack() {}

  // Push an element onto the stack
  void push(const T &value) { data_.push_back(value); }

  // Pop an element off the stack
  T pop() {
    if (!empty()) {
      T back = data_.back();
      data_.pop_back();
      return back;
    } else {
      throw std::out_of_range("Stack<>::pop(): empty stack");
    }
  }

  // Get the top element of the stack
  T &top() { return data_.back(); }

  // Get the size of the stack
  std::size_t size() const { return data_.size(); }

  // Check whether the stack is empty
  bool empty() const { return data_.empty(); }

private:
  std::vector<T> data_; // underlying data container
};

// Copy constructor templated on some type T2
template <typename T> template <typename T2> Stack<T>::Stack(Stack<T2> &other) {
  while (!other.empty()) {
    push(static_cast<T>(other.pop()));
  }
}

int main() {
  Stack<int> int_stack;
  int_stack.push(1);
  int_stack.push(2);
  int_stack.push(3);

  Stack<float> float_stack;
  float_stack.push(1.1);
  float_stack.push(2.2);

  Stack<int> int_stack2(float_stack); // Copy constructor
  std::cout << "int_stack2 size: " << int_stack2.size()
            << std::endl; // Output: "int_stack2 size: 2"

  return 0;
}