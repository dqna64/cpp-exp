#include <iostream>
#include <sstream>
class A {
public:
  A() : p{0}, q{0.0} {}
  A(int p, double q) : p{p}, q{q} {}

  int get_p() const { return p; }
  int get_q() const { return q; }

private:
  int p;
  double q;
};

class B {
public:
  B() = default;

  std::string get_a() {
    auto s = std::string("a.p: " + std::to_string(a.get_p()) + "\n" +
                         "a.q: " + std::to_string(a.get_q()));
    return s;
  }

private:
  // in-class initialisers used in default constructor
  A a = A{1, 2.0};
};

int main() {
  B b;
  std::cout << b.get_a() << std::endl;
}