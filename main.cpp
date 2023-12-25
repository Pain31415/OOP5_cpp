#include "time.h"

int main() {
    Time t1, t2, sum, diff;

    std::cout << "Enter the first time:\n";
    std::cin >> t1;

    std::cout << "Enter the second time:\n";
    std::cin >> t2;

    ++t1;
    t2--;

    if (t1 > t2) {
        std::cout << "Time 1 is greater than Time 2.\n";
    }
    else if (t1 == t2) {
        std::cout << "Time 1 is equal to Time 2.\n";
    }
    else {
        std::cout << "Time 1 is less than Time 2.\n";
    }

    std::cout << "Time 1: " << t1 << std::endl;
    std::cout << "Time 2: " << t2 << std::endl;

    std::cout << "Hour of Time 1: " << t1[0] << std::endl;
    std::cout << "Minute of Time 1: " << t1[1] << std::endl;
    std::cout << "Second of Time 1: " << t1[2] << std::endl;

    Time t3 = t1;
    t3 += t2;

    std::cout << "Time 3 (assigned from Time 1 and added Time 2): " << t3 << std::endl;

    return 0;
}