#include <iostream>

namespace problem {
/**
 * Base destructor not virtual, so when instance of Derived is
 * typed as Base, only the Base destructor is called, not the
 * Derived destructor.
 *
 */
class Base {
public:
  Base() { std::cout << "Base constructor" << std::endl; }
  ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
  Derived(int member) : leaked_member_(new int(member)) {
    std::cout << "Derived constructor" << std::endl;
  }
  ~Derived() {
    delete leaked_member_;
    std::cout << "Derived destructor" << std::endl;
  }

private:
  int *leaked_member_;
};

int main() {
  Base *obj = new Derived(5); // Upcasting

  delete obj; // Calls Derived destructor, then Base destructor

  return 0;
}
} // namespace problem

namespace solution {
/**
 * Base destructor is virtual, so when instance of Derived is
 * typed as Base, both the Base and Derived destructors are called.
 *
 */
class Base {
public:
  Base() { std::cout << "Base constructor" << std::endl; }
  virtual ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base {
public:
  Derived(int member) : cleaned_member_(new int(member)) {
    std::cout << "Derived constructor" << std::endl;
  }
  ~Derived() {
    delete cleaned_member_;
    std::cout << "Derived destructor" << std::endl;
  }

private:
  int *cleaned_member_;
};

int main() {
  Base *obj = new Derived(9); // Upcasting

  delete obj; // Calls Derived destructor, then Base destructor

  return 0;
}
} // namespace solution

int main() {
  std::cout << "==== Problem ====" << std::endl;
  problem::main();
  std::cout << "==== Solution ====" << std::endl;
  solution::main();
  return 0;
}