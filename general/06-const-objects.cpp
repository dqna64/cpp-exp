int main() {
  {
    class Point {
    public:
      Point(int a, int b) : x_{a}, y_{b} {}

      int &x() { return x_; }
      const int &x() const { return x_; }

      int &y() { return y_; }

    private:
      int x_;
      int y_;
    };

    // const object
    const auto p1 = Point{1, 2};
    p1.x();     // OK: existing const-qualified method called
    p1.y();     // ERROR: existing const-qualified method called
    p1.x() = 4; // ERROR: non-existent non-const method called
    p1.y() = 4; // ERROR: 'this' argument to member function 'y' has type 'const
                // Point', but function is not marked const

    // non-const object
    auto p2 = Point{1, 2};
    p2.x();     // OK: non-const method called
    p2.y();     // OK: non-const method called
    p2.x() = 4; // OK: non-const method called
    p2.y() = 4; // OK: non-const method called
  }
}