#include "ComplexNumber.hpp"

Complex::Complex() {
	/* Nothing to do */
}

Complex::Complex(double r, double i) {
	this->r = r;
	this->i = i;
}

Complex Complex::operator +(Complex c2) {
	Complex c3;
	c3.r=r+c2.r;
	c3.i=i+c2.i;
	return c3;
}

Complex Complex::operator -(Complex c2) {
	Complex c3;
	c3.r=r-c2.r;
	c3.i=i-c2.i;
	return c3;
}

Complex Complex::operator *(Complex c2) {
	Complex c3;
	c3.r=(r*c2.r)-(i*c2.i);
	c3.i=(i*c2.r)+(r*c2.i);
	return c3;
}

Complex Complex::operator /(Complex c2) {
	Complex c3;
	c3.r=((r*c2.r)+(i*c2.i))/((c2.r*c2.r)+(c2.i*c2.i));
	c3.i=((i*c2.r)-(r*c2.i))/((c2.r*c2.r)+(c2.i*c2.i));
	return c3;
}

bool Complex::operator == (Complex c2) {
	return (r==c2.r) && (i==c2.i);
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
	out << c.r << " + " << c.i << "i";
	return out;
}
