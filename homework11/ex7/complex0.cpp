// complex0.cpp
#include "complex0.h"

using std::cout;
using std::cin;

Complex::Complex()
{
    real = 0;
    imag = 0;
}
Complex::Complex(double x, double y)
{
    real = x;
    imag = y;
}
Complex::~Complex()
{
}
Complex Complex::operator+(const Complex & c) const
{
    return Complex(real + c.real, imag + c.imag);
}
Complex Complex::operator-(const Complex & c) const
{
    return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex & c) const
{
    return Complex(real * c.real - imag * c.imag, real * c.imag + c.real * imag);
}

Complex operator*(double n, const Complex & c) 
{
    return Complex(c.real * n, c.imag * n);
}
Complex operator~(const Complex & c)
{
    return Complex(c.real, -c.imag);
}
std::istream & operator>>(std::istream & os, Complex & c)
{
    cout << "real: ";
    os >> c.real;
    cout << "imagnary: ";
    os >> c.imag;
    return os;
}
std::ostream & operator<<(std::ostream & os, const Complex & c)
{
    os << "(" << c.real << "," << c.imag << "i)";
    return os;
}
