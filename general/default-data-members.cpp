#include <iostream>

/**
 * Demonstrate class constructor order pseudocode
 * for each data member in declaration order
 *   if it has a user-defined initialiser
 *     Initialise it using the user-defined initialiser
 *   else if it is a fundamental type (integral, pointer, bool, etc.)
 *     do nothing (leave it as whatever was in memory before)
 *   else
 *     Initialise it using its default constructor
 */

int main(void) {
  {
    class Economy {
    public:
      Economy() = default;

      int availability() const { return _availability; }
      int time() const { return _time; }

    private:
      int _availability = 42; // user-defined default value
      int _time; // uninitialized, will take default int value when default
                 // constructor is called
    };

    auto economyTicket = Economy{};
    std::cout << economyTicket.availability()
              << std::endl; // 42; _availability has
                            // user-defined default value
    std::cout << economyTicket.time()
              << std::endl; // 0; _time takes default int value due to default
                            // constructor
  }

  {
    class Business {
    public:
      Business(int availability) : _availability(availability){};

      int availability() const { return _availability; }
      int time() const { return _time; }

    private:
      int _availability; // uninitialized, but will be by member initializer
                         // list in single-parameter constructor
      int _time;         // uninitialized, and never will be
    };
    auto businessTicket = Business{56};
    std::cout << businessTicket.availability()
              << std::endl; // 56; _availability takes value passed into member
                            // initializer list
    std::cout << businessTicket.time()
              << std::endl; // prints some random value e.g. -432890; _time
                            // takes whatever value was in memory}
  }

  return 0;
}