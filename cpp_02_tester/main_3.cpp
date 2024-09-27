#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a(10);
    Fixed b(20);
    Fixed c(15.5f);

    // Comparison operators
    std::cout << (a < b) << std::endl;   // Expected: 1 (true)
    std::cout << (b > a) << std::endl;   // Expected: 1 (true)
    std::cout << (a == Fixed(10)) << std::endl;  // Expected: 1 (true)

    // Arithmetic operators
    Fixed result = a + c;
    std::cout << "a + c = " << result << std::endl;  // Expected: 25.5

    // Increment and decrement
    std::cout << "Pre-increment a: " << ++a << std::endl;  // Expected: 11
    std::cout << "Post-increment a: " << a++ << std::endl; // Expected: 11, then a becomes 12

    // min and max functions
    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;  // Expected: 12 (or previous a value)
    std::cout << "Max of a and b: " << Fixed::max(a, b) << std::endl;  // Expected: 20

    return 0;
}
/*
g++ -Wall -Wextra -Werror -std=c++98 -c Fixed.cpp -o Fixed.o
g++ -Wall -Wextra -Werror -std=c++98 -c main.cpp -o main.o
g++ main.o Fixed.o -o program
*/
