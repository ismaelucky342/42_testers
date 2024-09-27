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
/*
Probar la implementación básica de una clase en la forma canónica ortodoxa.

    Prueba de Constructor por Defecto:
        Crea un objeto usando el constructor por defecto y verifica que el valor inicial sea 0.
    Prueba de Constructor de Copia:
        Crea un segundo objeto copiando el primero y verifica que el valor copiado sea el mismo.
    Prueba de Operador de Asignación de Copia:
        Asigna un objeto a otro y verifica que los valores se copien correctamente.
    Prueba de Métodos getRawBits y setRawBits:
        Llama a getRawBits para verificar que devuelve el valor correcto.
        Usa setRawBits para modificar el valor y verifica que getRawBits lo devuelve correctamente.
*/