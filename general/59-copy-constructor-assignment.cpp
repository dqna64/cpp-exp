#include <cstddef>
#include <iostream>
struct Birb {
    size_t size_;
    double* ptr_;
    int* arr_;

    Birb(size_t size, double* ptr)
    : size_{size}
    , ptr_{ptr}
    , arr_{new int[size]} {
        std::cout << "Birb()\n";
    }

    Birb(const Birb& other) {
        std::cout << "Birb(const Birb&)\n";

        this->size_ = other.size_;
        this->ptr_ = other.ptr_;
        this->arr_ = new int[other.size_];
        for (size_t i = 0; i < other.size_; ++i) {
            this->arr_[i] = other.arr_[i];
        }
    }

    auto operator=(const Birb& other) -> Birb {
        std::cout << "operator=(const Birb&)\n";

        if (this == &other) {
            return *this;
        }

        delete[] arr_;
        this->size_ = other.size_;
        this->ptr_ = other.ptr_;
        this->arr_ = new int[other.size_];
        for (size_t i = 0; i < other.size_; ++i) {
            this->arr_[i] = other.arr_[i];
        }

        return *this;
    }
};

int main() {
    double d1 = 84932.4392;
    double d2 = 43892.2348;

    auto b1 = Birb{5, &d1}; // constructor
    auto b2 = b1; // copy constructor
    b2 = Birb{6, &d2}; // constructor, then copy assignment

    std::cout << b1.size_ << ", " << *(b1.ptr_) << "\n";
    std::cout << b2.size_ << ", " << *(b2.ptr_);
}