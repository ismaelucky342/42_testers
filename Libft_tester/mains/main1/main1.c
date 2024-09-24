#include "libft.h"
#include <stdio.h>

int main() {
    // Prueba de ft_strlen
    char *str = "Hello, Libft!";
    printf("Length of string: %zu\n", ft_strlen(str));

    // Prueba de ft_strlcpy y ft_strlcat
    char dest[50] = "Hello";
    char *src = ", World!";
    ft_strlcat(dest, src, 50);
    printf("Concatenated string: %s\n", dest);

    // Prueba de ft_strjoin
    char *joined_str = ft_strjoin("Hello", " World");
    printf("Joined string: %s\n", joined_str);
    free(joined_str);

    // Prueba de ft_strtrim
    char *trimmed_str = ft_strtrim("  Hello World  ", " ");
    printf("Trimmed string: %s\n", trimmed_str);
    free(trimmed_str);

    return 0;
}
