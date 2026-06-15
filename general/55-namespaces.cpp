
#include <iostream>

namespace quantum_universe {
    int zoom_level = 999999; // need to zoom in a lot to see it
} // namespace quantum_universe

struct AimlessRock {
    int mass = 435; // kg
};

namespace universe {
    double age = 13.8;
    namespace laniakea {
        double age = 13.6;

        namespace virgo {
            double age = 13.6;

            namespace milky_way {
                double age = 13.6;

                // Nested namespaces
                namespace solar_system {
                    double age = 4.571; // billion years
                }
            } // namespace milky_way
        } // namespace virgo
    } // namespace laniakea

    // Namespace alias: just a nickname for a namespace
    namespace home = laniakea::virgo::milky_way::solar_system;

    // === Ways to use `using`

    // 1. Type alias
    using Radiowave = std::string;
    // Equiv to `typedef struct node* Node` in C

    // Use the `::` global scope resolution operator to get something from the
    // global scope
    using ForeignObject = ::AimlessRock;

    // 2. `using` declaration
    // Bring `greater` from the `namespace std` into `namespace universe`
    using std::greater; // Now you can access with universe::greater

    // 3. `using` directive
    // Imports the entire contents of a namespace
    using namespace quantum_universe;
    // Now you access everything from namespace quantum_universe in namespace universe

    // ===

} // namespace universe

int main() {
    // Namespace alias
    std::cout << "Solar system is " << universe::home::age << " billion years old\n";

    // (1)
    auto msg = universe::Radiowave("A msg from the universe");
    auto fo = universe::ForeignObject();

    // (2)
    std::cout << "Is universe older than solar system? " << std::boolalpha
              << universe::greater()(universe::age, universe::home::age);

    // (3)
    std::cout << "Quantum universe zoom lv: " << universe::zoom_level << "\n";
}
