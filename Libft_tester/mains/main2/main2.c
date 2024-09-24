#include "libft.h"
#include <stdio.h>

int main() {
    // Prueba de ft_atoi
    char *num_str = "1234";
    int num = ft_atoi(num_str);
    printf("String to integer: %d\n", num);

    // Prueba de ft_itoa
    char *str_from_int = ft_itoa(5678);
    printf("Integer to string: %s\n", str_from_int);
    free(str_from_int);

    return 0;
}
