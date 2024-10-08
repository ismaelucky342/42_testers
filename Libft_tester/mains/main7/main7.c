#include "libft.h"
#include <stdio.h>

int main(void)
{
    // Prueba de ft_isdigit
    char c1 = '5';
    char c2 = 'a';
    printf("ft_isdigit('%c') = %d\n", c1, ft_isdigit(c1)); // Debe ser 1 (verdadero)
    printf("ft_isdigit('%c') = %d\n", c2, ft_isdigit(c2)); // Debe ser 0 (falso)

    // Prueba de ft_atoi
    char *num_str1 = "123";
    char *num_str2 = "-456";
    printf("ft_atoi('%s') = %d\n", num_str1, ft_atoi(num_str1)); // Debe ser 123
    printf("ft_atoi('%s') = %d\n", num_str2, ft_atoi(num_str2)); // Debe ser -456

    // Prueba de ft_itoa
    int num1 = 789;
    int num2 = -321;
    char *itoa_str1 = ft_itoa(num1);
    char *itoa_str2 = ft_itoa(num2);
    printf("ft_itoa(%d) = %s\n", num1, itoa_str1); // Debe ser "789"
    printf("ft_itoa(%d) = %s\n", num2, itoa_str2); // Debe ser "-321"
    free(itoa_str1); // Liberar memoria de ft_itoa
    free(itoa_str2);

    // Prueba de ft_isalnum
    char c3 = '9';
    char c4 = '#';
    printf("ft_isalnum('%c') = %d\n", c3, ft_isalnum(c3)); // Debe ser 1 (verdadero, es número)
    printf("ft_isalnum('%c') = %d\n", c4, ft_isalnum(c4)); // Debe ser 0 (falso, no es letra ni número)

    // Prueba de ft_memcmp para comparar dos secuencias de números
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3, 5};
    printf("ft_memcmp(arr1, arr2, 4 * sizeof(int)) = %d\n", 
           ft_memcmp(arr1, arr2, 4 * sizeof(int))); // Debe ser diferente a 0 porque 4 != 5

    return 0;
}
