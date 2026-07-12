
#include <iostream>
#include <string>
struct Plant {
    int height;
    std::string name;
};

// Create by value, return by value
// OKAY
auto fa(Plant a) -> Plant {
    return a;
}

// Create by value, return by reference
// PROBLEMATIC: returns a reference to stack memory
auto fb(Plant a) -> Plant& {
    return a;
}

// Create by reference, return by value
// OKAY
auto fc(Plant& a) -> Plant {
    return a;
}

// Create by reference return by reference
// OKAY
auto fd(Plant& a) -> Plant& {
    return a;
}

int main() {
    auto a = Plant{5, "hibicus"};
    auto& b = fb(a);
    std::cout << b.name << ", " << b.height << "\n";
    // ^^^ undefined behaviour: b is a reference to stack memory that has
    // gone out of scope already
    // If you're unlucky, it might even work!
}