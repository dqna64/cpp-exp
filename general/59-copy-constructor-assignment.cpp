#include <cstddef>
#include <iostream>
struct Birb {
    size_t size_;
    double* weight_;
    int* arr_;

    // === Constructor
    Birb(size_t size, double d)
    : size_{size}
    , weight_{new double{d}}
    , arr_{new int[size]} {
        std::cout << "Birb()\n";
    }

    // === Destructor
    // Implicitly marked noexcept, always make sure your
    // implementation abides by this rule.
    ~Birb() noexcept {
        std::cout << "~Birb()\n";
        delete weight_;
        delete[] arr_;
    }

    // === Copy constructor
    Birb(const Birb& other)
    : size_{other.size_}
    , weight_{new double{*(other.weight_)}}
    , arr_{new int[other.size_]} {
        std::cout << "Birb(const Birb&)\n";

        for (size_t i = 0; i < other.size_; ++i) {
            arr_[i] = other.arr_[i];
        }
    }

    // === Copy assignment
    // Should return Birb& not Birb.
    // Returning Birb means a new copy is created.
    auto operator=(const Birb& other) -> Birb& {
        std::cout << "operator=(const Birb&)\n";

        // ALWAYS guard agains self-assignment
        if (this == &other) {
            return *this;
        }

        delete weight_;
        delete[] arr_;
        size_ = other.size_;
        weight_ = new double{};
        *weight_ = *(other.weight_);
        arr_ = new int[other.size_];
        for (size_t i = 0; i < other.size_; ++i) {
            arr_[i] = other.arr_[i];
        }

        return *this;
    }

    // Birb(Birb&& other) noexcept = default;
    // auto operator=(Birb&& other) noexcept -> Birb& = default;

    // === Move constructor
    Birb(Birb&& other) noexcept
    : size_{other.size_}
    , weight_{other.weight_}
    , arr_{other.arr_} {
        std::cout << "Birb(Birb&&)\n";

        // Leave other in a valid but undefined state.
        other.weight_ = nullptr;
        other.arr_ = nullptr;
    }

    // === Move assignment
    // Should return Birb& not Birb.
    auto operator=(Birb&& other) noexcept -> Birb& {
        std::cout << "operator=(Birb&&)\n";

        // ALWAYS guard agains self-assignment
        if (this == &other) {
            return *this;
        }

        delete weight_;
        delete[] arr_;

        size_ = other.size_;
        weight_ = other.weight_;
        other.weight_ = nullptr;
        arr_ = other.arr_;
        other.arr_ = nullptr;

        return *this;
    }
};

int main() {
    {
        // === Demo of copy constructor and copy assignment
        std::cout << "=== Constructor\n";
        auto b1 = Birb{5, 84932.4392};

        std::cout << "=== Copy constructor\n";
        auto b2 = b1; // copy constructor

        std::cout << "=== Constructor, then copy assignment, then destructor\n";
        b2 = Birb{6, 43892.2348}; // constructor, then copy assignment

        std::cout << "=== Values\n";
        std::cout << b1.size_ << ", " << *(b1.weight_) << "\n";
        std::cout << b2.size_ << ", " << *(b2.weight_) << "\n";

        std::cout << "=== Destructors\n";
    }
    std::cout << "===\n";

    {
        // === Demo of move constructor and move assignment
        // NOTE: if you comment out your custom move constructor/assignment
        // implementations from the class Birb, notice that all these
        // fallback to copy constructor/assignment, NOT an implicitly generated move
        // constructor/assignment.
        std::cout << "=== Constructors\n";
        auto b1 = Birb{3, 9374.74638};
        auto b2 = Birb{8, 3290523.74};

        std::cout << "=== Move constructor\n";
        auto b3 = std::move(b1);

        std::cout << "=== Move assignment\n";
        b3 = std::move(b2);

        std::cout << "=== Values\n";
        // std::cout << b1.size_ << ", " << *(b1.weight_) << "\n";
        // std::cout << b2.size_ << ", " << *(b2.weight_) << "\n";
        // ^^^ These two would cause segfault bc b1 and b2 are now undefined
        std::cout << b3.size_ << ", " << *(b3.weight_) << "\n";

        std::cout << "=== Destructors\n";
    }
    std::cout << "===\n";

    {
        // === Demo of attempt to move a const object
        const auto b1 = Birb{3, 98439.38924};
        auto b2 = std::move(b1);
        // ^^ Calling std::move on a const object falls back to copy
        // constructor/assignment
    }
    std::cout << "===\n";
}