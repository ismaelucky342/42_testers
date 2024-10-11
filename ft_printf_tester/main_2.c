#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main() {
    char *puntero = "Hola mundo";
    char *cadena_vacia = "";
    int numero_negativo = -42;
    unsigned int entero_mas_grande = UINT_MAX;
    long long entero_largo = LONG_LONG_MAX;

    // Prueba básica
    printf("Hola mundo\n");
    ft_printf("Hola mundo\n");

    // Pruebas de longitud
    printf("| len %d\n", printf("Hola mundo"));
    ft_printf("| len %d\n", ft_printf("Hola mundo"));

    // Prueba de caracteres
    printf("| len %d\n", printf("prueba char %c %c %c %c", 'H', 'o', 'l', 'a'));
    ft_printf("| len %d\n", ft_printf("prueba char %c %c %c %c", 'H', 'o', 'l', 'a'));

    // Pruebas de cadenas
    printf("| len %d\n", printf("prueba string %s %s", "Hola", "mundo"));
    ft_printf("| len %d\n", ft_printf("prueba string %s %s", "Hola", "mundo"));

    // Prueba de puntero
    printf("| len %d\n", printf("prueba puntero %p", puntero));
    ft_printf("| len %d\n", ft_printf("prueba puntero %p", puntero));

    // Pruebas con enteros
    printf("| len %d\n", printf("prueba int %%d %d %d %d", 10, 11, 12));
    ft_printf("| len %d\n", ft_printf("prueba int %%d %d %d %d", 10, 11, 12));

    printf("| len %d\n", printf("prueba int %%i %i %i %i", 10, 11, 12));
    ft_printf("| len %d\n", ft_printf("prueba int %%i %i %i %i", 10, 11, 12));

    printf("| len %d\n", printf("prueba int %%u %u %u %u", 10, 11, 12));
    ft_printf("| len %d\n", ft_printf("prueba int %%u %u %u %u", 10, 11, 12));

    // Pruebas hexadecimales
    printf("| len %d\n", printf("prueba hexadecimal %x", 42424242));
    ft_printf("| len %d\n", ft_printf("prueba hexadecimal %x", 42424242));

    printf("| len %d\n", printf("prueba HEXADECIMAL %X", 42424242));
    ft_printf("| len %d\n", ft_printf("prueba HEXADECIMAL %X", 42424242));

    // Pruebas de punteros inválidos
    printf("| len %d\n", printf("prueba punteros %p", (void *)-14523));
    ft_printf("| len %d\n", ft_printf("prueba punteros %p", (void *)-14523));

    // Prueba de punteros nulos
    printf("| len %d\n", printf("prueba punteros nulos %p %p", (void *)0, (void *)0));
    ft_printf("| len %d\n", ft_printf("prueba punteros nulos %p %p", (void *)0, (void *)0));

    // Prueba de cadena vacía
    printf("| len %d\n", printf("prueba cadena vacía: %s\n", cadena_vacia));
    ft_printf("| len %d\n", ft_printf("prueba cadena vacía: %s\n", cadena_vacia));

    // Prueba con caracteres especiales
    printf("| len %d\n", printf("prueba con %% %s\n", "cadena"));
    ft_printf("| len %d\n", ft_printf("prueba con %% %s\n", "cadena"));

    // Prueba de un carácter fuera de rango
    printf("| len %d\n", printf("prueba char fuera de rango: %c\n", 256));
    ft_printf("| len %d\n", ft_printf("prueba char fuera de rango: %c\n", 256));

    // Prueba de un número negativo
    printf("| len %d\n", printf("prueba entero negativo: %d\n", numero_negativo));
    ft_printf("| len %d\n", ft_printf("prueba entero negativo: %d\n", numero_negativo));

    // Prueba de un entero más grande que UINT_MAX
    printf("| len %d\n", printf("prueba entero largo: %llu\n", entero_largo));
    ft_printf("| len %d\n", ft_printf("prueba entero largo: %llu\n", entero_largo));

    // Prueba con el valor máximo de un entero sin signo
    printf("| len %d\n", printf("prueba unsigned int máximo: %u\n", entero_mas_grande));
    ft_printf("| len %d\n", ft_printf("prueba unsigned int máximo: %u\n", entero_mas_grande));

    return 0;
}
