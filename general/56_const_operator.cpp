#include <iostream>
class simple_vec {
 public:
    // non-const overload of at(), acts as a setter
    auto at(int n) -> double& {
        return elems_[n];
    }

    // const-qualified overload of at(), acts as a getter
    auto at(int n) const -> double {
        return elems_[n];
    }

    auto operator[](int n) -> double& {
        return elems_[n];
    }

    auto operator[](int n) const -> const double& {
        return elems_[n];
    }

    auto print(int n) -> void {
        std::cout << "elems_[" << n << "]: " << elems_[n] << "\n";
    }

 private:
    double elems_[3] = {0, 0, 0};
};

int main() {
    auto v = simple_vec{};
    v.at(1); // This calls the non-const overload of the at() method
    v.at(1) = 5;
    v[1] = 5;
    v.print(1);

    const auto cv = simple_vec{};
    cv.at(1); // This calls the const-qualified overload of the at() method
    // cv.at(1) = 432; // ERROR: Expression is not assignableclang
    // cv[1] = 5; // ERROR: Expression is not assignableclang
}
