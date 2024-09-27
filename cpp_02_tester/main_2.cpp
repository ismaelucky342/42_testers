#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;            // Expected: 1234.43
    std::cout << "b is " << b << std::endl;            // Expected: 10
    std::cout << "c is " << c << std::endl;            // Expected: 42.4219
    std::cout << "d is " << d << std::endl;            // Expected: 10
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;  // Expected: 1234
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;  // Expected: 10
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;  // Expected: 42

    return 0;
}
/*
 Verificar la correcta conversión entre enteros, floats y valores de punto fijo.

    Prueba de Constructor con Entero:
        Crea un objeto pasando un entero y verifica que el valor se guarda correctamente.
    Prueba de Constructor con Float:
        Crea un objeto pasando un float y verifica la conversión a punto fijo.
    Prueba de Métodos toFloat y toInt:
        Llama a toFloat y toInt para verificar que los valores se convierten correctamente.
*/