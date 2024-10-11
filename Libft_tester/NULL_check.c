#include <stdio.h>
#include <stdlib.h>
#include "libft.h" // assuming ft_split and ft_strjoin are in libft.h

int main() {
    char *str = NULL;
    char **split_str = NULL;
    char *joined_str = NULL;

    // Test ft_split with NULL input
    split_str = ft_split(str, ' ');
    if (split_str == NULL) {
        printf("ft_split handled NULL input correctly\n");
    } else {
        printf("ft_split did not handle NULL input correctly\n");
        return 1;
    }

    // Test ft_strjoin with NULL inputs
    joined_str = ft_strjoin(NULL, NULL);
    if (joined_str == NULL) {
        printf("ft_strjoin handled NULL inputs correctly\n");
    } else {
        printf("ft_strjoin did not handle NULL inputs correctly\n");
        return 1;
    }

    joined_str = ft_strjoin("Hello, ", NULL);
    if (joined_str == NULL) {
        printf("ft_strjoin handled NULL second input correctly\n");
    } else {
        printf("ft_strjoin did not handle NULL second input correctly\n");
        return 1;
    }

    joined_str = ft_strjoin(NULL, "World!");
    if (joined_str == NULL) {
        printf("ft_strjoin handled NULL first input correctly\n");
    } else {
        printf("ft_strjoin did not handle NULL first input correctly\n");
        return 1;
    }

    return 0;
}