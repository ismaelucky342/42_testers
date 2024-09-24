#include "libft.h"
#include <stdio.h>

int main() {
    char memory[20];

    // Prueba de ft_memset
    ft_memset(memory, 'A', 10);
    printf("Memory after memset: %s\n", memory);

    // Prueba de ft_bzero
    ft_bzero(memory, 10);
    printf("Memory after bzero: %s\n", memory);

    // Prueba de ft_memcpy
    char src[] = "Libft Memcpy";
    ft_memcpy(memory, src, 12);
    printf("Memory after memcpy: %s\n", memory);

    // Prueba de ft_memmove
    ft_memmove(memory + 4, memory, 8);
    printf("Memory after memmove: %s\n", memory);

    return 0;
}
