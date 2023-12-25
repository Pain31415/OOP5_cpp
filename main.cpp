#include "complex.h"

int main() {
    Complex c1, c2, sum, diff;

    std::cout << "Enter the first complex number:\n";
    std::cin >> c1;

    std::cout << "Enter the second complex number:\n";
    std::cin >> c2;

    sum = c1 + c2;
    diff = c1 - c2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;

    if (c1 == c2) {
        std::cout << "The complex numbers are equal.\n";
    }
    else {
        std::cout << "The complex numbers are not equal.\n";
    }

    return 0;
}