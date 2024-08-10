#include <assert.h>
#include <iostream>
#include <string>

class EnergyBall;
class MatterBall;

const long long C = 299792458;

class EnergyBall {
public:
	EnergyBall(int energy)
	: energy_{energy} {}

	friend EnergyBall operator+(EnergyBall const& a, EnergyBall const& b);

	friend std::ostream& operator<<(std::ostream& os, EnergyBall const& e);

	/**
	 * This doesn't work (member function). operator<< must be implemented as a
	 * friend function
	 *
	 */
	// std::ostream& operator<<(std::ostream& os) {
	// 	os << this->energy_;
	// 	return os;
	// };

	/**
	 * This friend function is declared in both `class EnergyBall` and `class MatterBall`
	 * so that it can access private fields of both classes.
	 */
	friend long long operator+(MatterBall const& mb, EnergyBall const& eb);

	/**
	 * Operator pairings; if you implement operator+(TypeA, TypeB)
	 * then you should also implement operator+(TypeB, TypeA)
	 */
	friend long long operator+(EnergyBall const& eb, MatterBall const& mb);

	/**
	 * operator== could also be implemented as a friend function. In fact
	 * that probably makes more semantic sense for a binary operator.
	 */
	bool operator==(EnergyBall const& other) const {
		return energy_ == other.energy_;
	}

	/**
	 * operator+= should be implemented as a non-const member function,
	 * bc it involves mutating the instance.
	 */
	EnergyBall& operator+=(EnergyBall const& other) {
		energy_ += other.energy_;
		return *this;
	}

private:
	int energy_;
};

EnergyBall operator+(EnergyBall const& a, EnergyBall const& b) {
	return EnergyBall(a.energy_ + b.energy_);
}

std::ostream& operator<<(std::ostream& os, EnergyBall const& e) {
	os << e.energy_;
	return os;
}

class MatterBall {
public:
	MatterBall(int mass)
	: mass_{mass} {}

	friend long long operator+(MatterBall const& mb, EnergyBall const& eb);
	friend long long operator+(EnergyBall const& eb, MatterBall const& mb);

private:
	int mass_;
};

long long operator+(MatterBall const& mb, EnergyBall const& eb) {
	return mb.mass_ * std::pow(C, 2) + eb.energy_;
}

long long operator+(EnergyBall const& eb, MatterBall const& mb) {
	return mb + eb;
}

int main() {
	auto e1 = EnergyBall(4);
	auto e2 = EnergyBall(5);
	auto e3 = e1 + e2;
	assert(e3 == 9);

	auto m1 = MatterBall{5};
	auto total = m1 + e3;
	assert(total == std::pow(C, 2) * 5 + 9);

	e3 += e1;
	assert(e3 == 13);

	auto total2 = e1 + m1;
}
