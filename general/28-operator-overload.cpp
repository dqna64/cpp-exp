#include <compare> // Required for std::strong_ordering
#include <iostream>
#include <string>
namespace a {
struct A {
  int operator()() { return 1; }
};

void main() {
  auto new_A = A();
  int res = new_A();
}
} // namespace a

namespace spaceship {

class Person {
public:
  Person(const std::string &name, int age) : name_(name), age_(age) {}

  // Implement the spaceship operator
  std::strong_ordering operator<=>(const Person &other) const {
    if (auto cmp = name_.compare(other.name_); cmp < 0) {
      return std::strong_ordering::less;
    } else if (cmp > 0) {
      return std::strong_ordering::greater;
    } else {
      return age_ <=> other.age_;
    }
  }

  // Accessor functions for demonstration purposes
  std::string getName() const { return name_; }
  int getAge() const { return age_; }

private:
  std::string name_;
  int age_;
};

int main() {
  Person alice("Alice", 30);
  Person bob("Bob", 25);
  Person charlie("Charlie", 30);
  Person alice2("Alice", 30);
  Person alice3("Alice", 23);

  auto compare_and_print = [](const Person &p1, const Person &p2) {
    auto cmp = p1 <=> p2;
    if (cmp < 0) {
      std::cout << p1.getName() << " < " << p2.getName() << std::endl;
    } else if (cmp > 0) {
      std::cout << p1.getName() << " > " << p2.getName() << std::endl;
    } else {
      std::cout << p1.getName() << " == " << p2.getName() << std::endl;
    }
  };

  compare_and_print(alice, bob);
  compare_and_print(bob, charlie);
  compare_and_print(alice, charlie);
  compare_and_print(alice, alice2);
  compare_and_print(alice, alice3);

  return 0;
}

} // namespace spaceship

int main() {
  a::main();
  spaceship::main();
}