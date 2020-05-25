// complex0.h

#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class Complex
{
    private:
	double real;
	double imag;
    public:
	Complex();
	Complex(double, double);
	~Complex();
	Complex operator+(const Complex &) const;
	Complex operator-(const Complex &) const;
	Complex operator*(const Complex &) const;
	friend Complex operator*(double, const Complex &);
	friend Complex operator~(const Complex &);
	friend std::istream & operator>>(std::istream &, Complex &);
	friend std::ostream & operator<<(std::ostream &, const Complex &);
};
#endif
