#include <iostream>

class Complex {
	friend std::ostream &operator<<(std::ostream &out, const Complex &c);

private:
	const double EPSILON=1e-4; // The accuracy
	double r = 0; // real part, 0 by default
	double i = 0; // imaginary part, 0 by default

public:
	Complex(); // Constructor with no arguments
	Complex(double r, double i); // Constructor

	Complex operator +(Complex c2);
	Complex operator -(Complex c2);
	Complex operator *(Complex c2);
	Complex operator /(Complex c2);
	bool operator == (Complex c2);
};

