#include <iostream>

namespace construction_order {
#include <iostream>
struct A {
  A() { std::cout << "A "; }
};
struct B : A {
  B() { std::cout << "B "; }
};
struct C : A {
  C() { std::cout << "C "; }
};
struct alphabet : B, A, C {
  alphabet() : c{}, a{} { std::cout << "alphabetical"; }
  C c;
  B b;
  A a;
};
int main() {
  {
    std::cout << "=== construction order ===\n";
    alphabet alpha;
    std::cout << std::endl;
  }
}
} // namespace construction_order

namespace destruction_order {
struct A {
  ~A() { std::cout << "A"; }
};
struct B : A {
  ~B() { std::cout << "B "; }
};
struct C : A {
  ~C() { std::cout << "C "; }
};
struct alphabet : A, B, C {
  ~alphabet() { std::cout << "alphabetical "; }
  B b;
  C c;
};
int main() {
  {
    std::cout << "=== destruction order ===\n";
    alphabet alpha;
    std::cout << std::endl;
  }
}
} // namespace destruction_order

int main() {
  construction_order::main();
  destruction_order::main();

  return 0;
}