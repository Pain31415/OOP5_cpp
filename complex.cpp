#include "complex.h"


Complex::Complex() : real(0.0), imag(0.0) {}

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

std::istream& operator>>(std::istream& in, Complex& complex) {
    std::cout << "Enter real part: ";
    in >> complex.real;
    std::cout << "Enter imaginary part: ";
    in >> complex.imag;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    out << complex.real << " + " << complex.imag << "i";
    return out;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

Complex Complex::operator()() const {
    return *this;
}