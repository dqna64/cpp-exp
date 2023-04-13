#include <iostream>

namespace sample0 {
/**
 * When vtable non-empty, each method will have a pointer to the vtable to look
 * up the method implementation. When vtable empty, each method will have a
 * pointer to the class's code. This is called "early binding" or "static
 * binding" because the compiler knows which method to call at compile time.
 * This example demonstrates the latter.
 *
 */
class BaseClass {
public:
  BaseClass() { std::cout << "BaseClass constructor" << std::endl; }
  std::string get_class_name() const { return "BaseClass"; };

private:
};

class SubClass : public BaseClass {
public:
  SubClass() { std::cout << "SubClass constructor" << std::endl; }
  std::string get_class_name() const { return "SubClass"; }

private:
};

void print_class_name(const BaseClass base) {
  std::cout << base.get_class_name() << '\n';
}

void print_class_name_ref(const BaseClass &base) {
  std::cout << base.get_class_name() << '\n';
}

int main() {

  std::cout << "==== Sample 0 ====\n";
  BaseClass base_class;
  SubClass subclass;
  print_class_name_ref(base_class); // "BaseClass"
  print_class_name_ref(subclass);   // "BaseClass" because get_class_name() is
                                    // not virtual
  return 0;
}
} // namespace sample0

namespace sample1 {

/**
 * Must pass class instances by reference or pointer to avoid slicing and
 * achieve polymorphism in context of "don't pay for what you don't use".
 * Don't pass class instances by value.
 *
 */

class BaseClass {
public:
  virtual std::string get_class_name() const { return "BaseClass"; };
  int get_member() const { return member_; }

private:
  int member_;
};

class SubClass : public BaseClass {
public:
  std::string get_class_name() const override { return "SubClass"; }

private:
  int subclass_data_;
};

void print_class_name(const BaseClass base) {
  std::cout << base.get_class_name() << ' ' << base.get_member() << '\n';
}

void print_class_name_ref(const BaseClass &base) {
  std::cout << base.get_class_name() << ' ' << base.get_member() << '\n';
}

int main() {

  std::cout << "==== Sample 1 ====\n";
  BaseClass base_class;
  SubClass subclass;
  print_class_name(base_class);     // "BaseClass 0"
  print_class_name(subclass);       // "BaseClass 0"
  print_class_name_ref(base_class); // "BaseClass 0"
  print_class_name_ref(subclass);   // "SubClass 0"
  return 0;
}
} // namespace sample1

namespace sample2 {
class BaseClass {
public:
  virtual std::string get_class_name() const { return "BaseClass"; };
  int get_member() const { return member_; }

  ~BaseClass() { std::cout << "Destructing base class\n"; }

private:
  int member_;
};

class SubClass : public BaseClass {
public:
  std::string get_class_name() const override { return "SubClass"; }

  ~SubClass() { std::cout << "Destructing subclass\n"; }
};

int main() {
  std::cout << "==== Sample 2 ====\n";
  auto baseclass =
      static_cast<std::unique_ptr<BaseClass>>(std::make_unique<BaseClass>());
  auto baseclass_subclass =
      static_cast<std::unique_ptr<BaseClass>>(std::make_unique<SubClass>());
  std::cout << baseclass->get_class_name() << std::endl;          // "BaseClass"
  std::cout << baseclass_subclass->get_class_name() << std::endl; // "SubClass"
  return 0;
};
} // namespace sample2

namespace sample3 {

class GrandClass {
private:
  char char_data_;

public:
  GrandClass(char char_data) : char_data_(char_data) {}
  void print_class_name() const { std::cout << "GrandClass" << std::endl; }
};
class BaseClass : public GrandClass {
private:
  int int_data_;

public:
  BaseClass(char char_data, int int_data)
      : GrandClass(char_data), int_data_(int_data) {}
  void print_class_name() const { std::cout << "BaseClass" << std::endl; }
};
class SubClass : public BaseClass {
private:
  double double_data;

public:
  SubClass(char char_data, int int_data, double double_data)
      : BaseClass(char_data, int_data), double_data(double_data) {}
  void print_class_name() const { std::cout << "SubClass" << std::endl; }
};

int main() {
  std::cout << "==== Sample 3 ====\n";
  GrandClass grandClass = GrandClass('a');
  BaseClass baseClass = BaseClass('a', 1);
  BaseClass subClassStaticallyBaseClass = SubClass('b', 2, 3.0);
  SubClass subClass = SubClass('c', 4, 5.0);
  grandClass.print_class_name();
  baseClass.print_class_name();                                  // "BaseClass"
  subClassStaticallyBaseClass.print_class_name();                // "BaseClass"
  subClass.print_class_name();                                   // "SubClass"
  std::cout << sizeof(grandClass) << std::endl;                  // 1
  std::cout << sizeof(baseClass) << std::endl;                   // 8
  std::cout << sizeof(subClassStaticallyBaseClass) << std::endl; // 8
  std::cout << sizeof(subClass) << std::endl;                    // 16
  return 0;
}
} // namespace sample3

namespace sample4 {
/**
 * When constructing a class, the constructor of the base class is
 * called at a point in time where the derived class is not yet fully
 * constructed.
 * Similar problem for destruction.
 * Basically, expect unexpected behaviour when using virtual functions
 * in constructors and destructors.
 *
 */
class Animal {
public:
  Animal() { speak(); }
  ~Animal() { speak(); }
  virtual void speak() { std::cout << "Animal speaks" << std::endl; }
};

class Dog : public Animal {
public:
  void speak() override { std::cout << "Woof" << std::endl; }
};

int main() {
  // Unexpected behaviour:
  // Upon construction, the virtual override function Dog::speak() is
  // not yet available, so the base class Animal::speak() is called.
  // Upon destructions, the virtual override function Dog::speak() is
  // no longer available, so the base class Animal::speak() is called.
  Dog *fido = new Dog();
  return 0;
}

} // namespace sample4

namespace sample5 {
/**
 * @brief Calling virtual functions during construction of polymorphic objects
 * can result in unexpected behaviour.
 *
 */
class Base {
public:
  Base() {
    // Calling the virtual function during construction of an instance of
    // this Base class, when the Derived class is not yet fully constructed.
    // (This is generally not recommended)
    foo();
  }

  virtual void foo() { std::cout << "Base::foo()" << std::endl; }
};

class Derived : public Base {
public:
  Derived() {
    // foo() in Derived class is not fully constructed yet,
    // calling it here can result in unexpected behavior
    foo();
  }

  void foo() override { std::cout << "Derived::foo()" << std::endl; }
};

int main() {
  std::cout << "==== Sample 5 ====\n";
  Derived d; // Creating an object of Derived class. The constructor of
             // Derived class calls foo() on the partially constructed object,
             // resulting in the incorrect vtable being used.
             // Output: Base::foo() then Derived::foo()
  d.foo();   // Calling foo() on the fully constructed object.
             // Output: Derived::foo()
  return 0;
}

} // namespace sample5
int main() {
  sample0::main();
  sample1::main();
  sample2::main();
  sample3::main();
  sample4::main();
  sample5::main();
}