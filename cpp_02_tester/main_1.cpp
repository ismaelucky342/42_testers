#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;                    // Default constructor
    Fixed b(a);                 // Copy constructor
    Fixed c;                    // Default constructor
    c = b;                      // Copy assignment operator
    
    std::cout << a.getRawBits() << std::endl;  // Expected: 0
    std::cout << b.getRawBits() << std::endl;  // Expected: 0
    std::cout << c.getRawBits() << std::endl;  // Expected: 0

    a.setRawBits(42);
    std::cout << a.getRawBits() << std::endl;  // Expected: 42

    return 0;
}
