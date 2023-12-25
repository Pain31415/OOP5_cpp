#include "date.h"

int main() {
    Date d1, d2, result;

    std::cout << "Enter the first date:\n";
    std::cin >> d1;

    ++d1;
    d2--;

    if (d1 > d2) {
        std::cout << "Date 1 is greater than Date 2.\n";
    }
    else if (d1 == d2) {
        std::cout << "Date 1 is equal to Date 2.\n";
    }
    else {
        std::cout << "Date 1 is less than Date 2.\n";
    }

    std::cout << "Date 1: " << d1 << std::endl;
    std::cout << "Date 2: " << d2 << std::endl;

    result = d1;
    result += 5;

    std::cout << "Result (assigned from Date 1 and added 5 days): " << result << std::endl;

    return 0;
}