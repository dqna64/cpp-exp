#include <iostream>

class Economy {
public:
  Economy() = default;

  int availability() const { return _availability; }
  int time() const { return _time; }

private:
  int _availability = 42;
  int _time;
};

int main(void) {
  auto ticket = Economy{};
  std::cout << ticket.availability() << std::endl; // 42; _availability has
                                                   // user-defined default value
  std::cout << ticket.time()
            << std::endl; // 0; _availability takes default int value
  return 0;
}